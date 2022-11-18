#include<iostream>
using namespace std;

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

	//������������

	Fraction() // �� ���������
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)// ��� ����� �����
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "largConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator) //��� ��������� � �����������
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	

	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//�������� (������������)
	
	Fraction& operator=(const Fraction& other)
	{
		{
			this->integer = other.integer;
			this->numerator = other.numerator;
			this->denominator = other.denominator;
			cout << "CopyAssigment:\t" << this << endl;
			return *this;
		}
	}
	// ������
	void print()const
	{
		if (integer)
			cout << integer;
		if (numerator)
			cout << numerator << "/" << denominator;
		cout << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Fraction �;
	�.print();

	Fraction B = 1;
	B.print();

	Fraction C(2, 3);
	C.print();
	//� �� �������, ��� ������ ������
	//� ��� ������ ������ ���������(((

		
}   
