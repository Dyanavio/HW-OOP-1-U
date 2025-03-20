#include <iostream>
#include <string>

using namespace std;

class Triangle 
{
protected:
	double a, b, c;

public:
	Triangle(double x, double y, double z) :a(x), b(y), c(z) { } //cout<<"constructor Triangle"<<endl;}
	double perim() { return a + b + c; }
	void print() { cout << "a=" << a << " b=" << b << " c=" << c << endl; }
	void print(char ch) { cout << "a=" << a << ch << " b=" << b << ch << " c=" << c << endl; }
	~Triangle() {} //cout<<"destructor Triangle"<<endl;	}
};

class Isosceles :public Triangle 
{
public:
	Isosceles(double x, double y) :Triangle(x, y, y) {} //cout<<"constructor Iso"<<endl;	}
	void print(){cout<<"a="<<a<<" b=c="<<c<<endl;}
	//	using Triangle::print;
	~Isosceles() {} //cout<<"destructor Iso"<<endl;}
};

class Equal : public Isosceles
{
public:
	Equal(double x) : Isosceles(x, x) { }
	void print()
	{
		cout << "Equal: a = b = c: " << a << endl;
	}
	using Isosceles::print;
};

int main()
{
	Triangle t(1, 1, 1);
	Isosceles is(2, 5);
	Equal eq(15);

	t.print();
	is.print();
	eq.print();

	t.print('\n');
	is.print('\n');
	eq.print('\n');

	cout << "Perimeter counting method does not have to be overloaded in the derived classes: " << eq.perim() << endl;


}
//Завдання 2. Створити три трикутники різних типів, викликати для них методи print з параметрами та без.
//Завдання 4. Викоритовуючи клас Equal зробити відправку задачі контесту на eolymp Рівносторонній трикутник