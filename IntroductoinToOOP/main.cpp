#include<iostream>
using namespace std;
using std::cout;

class Point
{
	double x;
	double y;
public: 
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x) // написали set методы
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//		Constructors:
	/*Point()
	{
		x = y = double(); //значения по умолчанию для double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "largConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
 		cout << "Destructor:\t" << this << endl;
	}


	//Метод distance
	double distance (const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print() const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};
//Чтобы передать параметры в функцию, и чтобы они не копировались, нужно передать их по ссылке. 
//Чтобы функция не изменила переданные параметры, ссылку надо сделать константной

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT
#define DISTANCE_CHEK
//#define CONSTRUCTIONS_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef STRUCT_POINT
	cout << "Hello OOP" << endl;

	int a; // объявление переменной 'a' типа 'int'
	Point A; // объявление переменной 'A' типа 'Point'
			 //создание объекта 'A' структуры 'Point'
			 //объявление экземпляра 'A' структуры 'Point'
	A.x = 2; // координаты точки А по оси х
	A.y = 3;// координаты точки А по оси y
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;//объявили указатель 
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

#ifdef DISTANCE_CHEK
	Point A;
	A.set_x(2); //вызвали set методы
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "\n-------------------------------------------------\n"; // разделила строкой, чтобы было понятно, что к чему относится)
	cout << "Расстояние от точки A до точки B: " << A.distance(B) << endl;
	cout << "\n-------------------------------------------------\n";
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << "\n-------------------------------------------------\n";
	cout << "Расстояние между А и В: " << distance(A, B) << endl;
	cout << "\n-------------------------------------------------\n";
	cout << "Расстояние между B и A: " << distance(B, A) << endl;

#endif // DISTANCE_CHEK

#ifdef CONSTRUCTIONS_CHEK
	Point A; //Default constructor
	A.print();

	Point B = 5;//Single-argument constructor
	B.print();

	Point C(8);//Single-argument constructor
	C.print();

	Point D(5, 8);// Parametrised constructor
	D.print();

	Point E = D;
	E.print();//CopyConstructor  
#endif // CONSTRACTIONS_CHEK

}