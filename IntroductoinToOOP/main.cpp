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
	//Метод distance
	double distance (Point tochka_b)
	{
		double x_distance = this->x - tochka_b.x;
		double x_distance = this->y - tochka_b.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	//ничего не получается(

};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define STRUCT_POINT

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

	Point A;
	A.set_x(2); //вызвали set методы
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	Point B;
	B.set_x(8);
	B.set_y(6);
	cout << B.get_x() << "\t" << B.get_y() << endl;
	cout << "Расстояние от A до B: " << endl;
	cout << A.distance (B) << endl;
	cout << "Расстояние между А и В: " << endl;
	cout << distance(A, B) << endl;
}