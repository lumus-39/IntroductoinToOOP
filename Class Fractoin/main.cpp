#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define WIDTH 27

class Fraction;
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (Fraction left, Fraction right);
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction& left, Fraction right);


class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	// get методы
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
	//set методы
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
		cout << std::left <<"DefaultConstructor:" << this << endl;
	}
	Fraction(int integer)// для целой части
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout.width(WIDTH);
		cout << std::left << "SingleArgConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator) //для числителя и знаменателя
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout.width(WIDTH);
		cout << std::left << "Constructor:" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator) // по умолчанию
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

	Fraction& operator = (const Fraction& other)//оператор присваивания
	{
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "AssignmentOperator:\t" << this << endl;
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
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	//Не понимаю, как сделать, чтобы инкремент и декремент изменяли не только целую часть
	
	// Methods
	void to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
	} 
	void to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
	}
	
	Fraction turn() const//меняем числитель и знаменатель местами для деления дроби
	{
		Fraction turn = *this;
		turn.to_improper();
		int buffer = turn.numerator;
		turn.numerator = turn.denominator;
		turn.denominator = buffer;
		return turn;
	}
	/*void reduce()
	{
		
	}*/
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
	Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;
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

//#define CONSCRUCTORS_CHECK

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

	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	Fraction C = A * B;
	C.print();
	(A/B).print();
	A *= B;
	A.print();
	/*for (Fraction i(1, 2); i.get_integer() < 6; ++i)
	{
		i.print();
	}*/

	
	cout << (Fraction(1, 2) != Fraction(2, 4)) << endl;
}
