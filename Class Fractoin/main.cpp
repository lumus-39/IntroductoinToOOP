#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define WIDTH 27

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (Fraction left, Fraction right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	// get ������
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	//set ������
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	// Constructor
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)// ��� ����� �����
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator) //��� ��������� � �����������
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator) // �� ���������
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	Fraction& operator = (const Fraction& other)//�������� ������������
	{
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout.width(WIDTH);
			cout << std::left << "AssignmentOperator:" << this << endl;
			return *this;
		}
	}
	Fraction& operator *= (const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator /= (const Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator += (const Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction& operator -= (const Fraction& other)
	{
		return *this = *this - other;
	}
	//----------------------------------------------------
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	

	// Methods
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}

	Fraction turn() const//������ ��������� � ����������� ������� ��� ������� �����
	{
		Fraction turn = *this;
		turn.to_improper();
		int buffer = turn.numerator;
		turn.numerator = turn.denominator;
		turn.denominator = buffer;
		return turn;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			less = numerator;
			more = denominator;
		}
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD - Greatest Coomon Division
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	void print()const
	{
		if (integer)
			cout << integer << " ";
		if (numerator)
		{
			cout << numerator << "/" << denominator;
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();

}
Fraction operator/(Fraction left, Fraction right)
{
	return left * right.turn();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator > (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;
}
bool operator < (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	if (left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator())
		return true;
	else
		return false;
}
bool operator >= (const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}
bool operator <= (const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
ostream& operator << (ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numerator())
	{
		os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	else os << 0;
	return os;
}
istream& operator >> (istream& is, Fraction& obj)
{
	int integer; cin >> integer;
	int numerator; cin >> numerator;
	int denominator; cin >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}


	//#define CONSCRUCTORS_CHECK
	//#define ARITHMETICAL_OPERATORS
	//#define INCREMENT_CHECK
	void main()
	{
		setlocale(LC_ALL, "");

#ifdef CONSCRUCTORS_CHECK
		Fraction A; //Default constructor
		A.print();

		Fraction B = 5; //Single-argument constructor
		B.print();

		Fraction C(1, 2);
		C.print();

		Fraction D(2, 3, 4);
		D.print();

		D.to_improper();
		D.print();

		D.to_proper();
		D.print();
#endif //CONSCRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS
		Fraction A(2, 3, 4);
		A.print();
		Fraction B(3, 4, 5);
		B.print();
		Fraction C = A * B;
		C.print();
		(A / B).print();
		A *= B;
		A.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_CHECK

		for (Fraction i(1, 2); i.get_integer() < 10; i++)
		{
			i.print();
		}

		cout << (Fraction(1, 2) != Fraction(2, 4)) << endl;


#endif // INCREMENT_CHECK

		Fraction A(2, 3, 4);
		cout << A << endl;
	}
	//Fraction A;
	//cout << "������� ������� �����: "; cin >> A;