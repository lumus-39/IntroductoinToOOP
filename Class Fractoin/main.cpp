#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
using std::cout;
using std::cin;

#define WIDTH 27
#define delimiter "\n_______________________________________________\n"

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
		cout << std::left << "DefaultConstructor:" << this << endl;
	}
	explicit Fraction(int integer)// для целой части
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
	Fraction(double decimal)
	{
		integer = decimal;
		denominator = 1000000000;
		numerator = (decimal - integer) * denominator;
		reduce();
	}
	~Fraction()
	{
		cout.width(WIDTH);
		cout << std::left << "Destructor:" << this << endl;
	}

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}
	Fraction& operator = (const Fraction& other)//оператор присваивания
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
	// Type-cast operator
	explicit operator int()const
	{
		return integer;
	}
	explicit operator double()const
	{
		return integer + (double)numerator / denominator;
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

	Fraction turn() const//меняем числитель и знаменатель местами для деления дроби
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

	// homework

	
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
std::ostream& operator << (ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer() << " ";
	if (obj.get_numerator())
	{
		os << obj.get_numerator() << "/" << obj.get_denominator();
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& obj)
{
	obj = Fraction();
	//obj(integer, numerator, denominator);
	int number[3] = {}; // в этом массиве будут хранится числовые значения полученные из строки
	
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer; //cin сохраняет данные в переменной до пробела
	//для того, чтобы ввести строку с пробелами нужно использовать cin.getline()
	is.getline(buffer, SIZE);
	
	char delimeters[] = " /()";
	int n = 0;//счетчик полученных чисел
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
	{
		number[n++] = std::atoi(pch);//функция atoi() - ASCII string to integer принимает строку,
		// и если строка является числом, то возвращает int-вый эквивалент этого числа
	}
	
	obj = Fraction();
	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2:
		obj.set_numerator(number[0]);
		obj.set_denominator(number[1]);
		break;
	case 3:
		obj.set_integer(number[0]);
		obj.set_numerator(number[1]);
		obj.set_denominator(number[2]);
		
	}
	return is;
}


	//#define CONSCRUCTORS_CHECK
	//#define ARITHMETICAL_OPERATORS
	//#define INCREMENT_CHECK
    //#define ISREAM_OPERATOR_CHECK
    //#define TYPE_CONVERSION_BASICS
    //#define CONVERSION_FROM_OTHER_TO_CLASS
    //#define CONVERSION_FROM_CLASS_TO_OTHER
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

#ifdef ISREAM_OPERATOR_CHECK

		Fraction A;
		cout << "Введите простую дробь: ";
		cin >> A;
		cout << delimeter << endl;
		cout << A << endl;
		cout << delimeter << endl;
#endif // ISREAM_OPERATOR_CHECK

#ifdef TYPE_CONVERSION_BASICSдд
		
		cout << (double)7 / 2 << endl;

		int a = 2;
		double b = 3;
		int c = b;
		int d = round(4.49);
		cout << d << endl;
#endif // TYPE_CONVERSION_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS		
		int a = 2;
		Fraction A = 5; //Single-argument constructor
		cout << A << endl;
		cout << delimiter << endl;

		Fraction B;//Default constructor
		B = 8;
		cout << B << endl;//Assignment constructor  
#endif // CONVERSION_FROM_OTHER_TO_CLASS
#ifdef CONVERSION_FROM_CLASS_TO_OTHER

		Fraction A(2, 3, 4);
		cout << A << endl;

		int a = (int)A;
		cout << a << endl;

		double b = (double)A;
		cout << b << endl;
#endif // CONVERSION_FROM_CLASS_TO_OTHER

		Fraction A = 2.75;
		cout << A << endl;


	}
