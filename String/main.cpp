#include<iostream>
using namespace std;
using std::cout;
using std::cin;

class String
{
	char* str;
	int length;
public:
	const char* get_str()const
	{
		return str;
	}
	int get_length()const
	{
		return length;
	}
	String(int length = 15)
	{
		this->length = length;
		this->str = new char[length];
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		length = strlen(str);
		this->str = new char [length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = str[i];
		this->str[length] = '\0';
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		this->length = other.length;
		this->str = new char [length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Descructor:\t" << this << endl;
	}
	
	String& operator = (const String& other)
	{
		this->length = other.length;
		this->str = new char [length + 1];
		for (int i = 0; i < length; i++)
			this->str[i] = other.str[i];
		this->str[length] = '\0';
		return *this;
		cout << "CopyAssignment:\t" << this << endl;
	}
	//String& operator + (const String& left, const String& right)
	
	
	void Print()const
	{
		cout << length << endl;
		cout << str << endl;
	}
};

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;
	//String str3 = str1 + str2;
	//cout << str3 << endl;
	

}