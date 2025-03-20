#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Figure
{
private:
	static int count;
public:
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
};

class Triangle : public Figure
{
private:
	double side1;
	double side2;
	double side3;
public:
	Triangle(int a, int b, int c)
	{
		side1 = a;
		side2 = b;
		side3 = c;
	}
	double getArea() override
	{
		double p = getPerimeter() / 2;
		return sqrt();
	}
	double getPerimeter() override
	{
		return side1 + side2 + side3;
	}
};

int Figure::count = 0;
int main()
{
	
}

//Створити абстрактний клас фігура з чисто віртуальними методами, що знаходять периметр та площу. Створити класи для різних типів фігур , що спадкують клас фігура. Створити екземпляри класів. (тобто переробити завдання 3 користуючись новими знаннями)
//4. В класі фігура створити статичне поле, що буде зберігати кількість створених фігур.На початку роботи програми та після заповнення масиву, вивести інформацію про кількість об'єктів типу фігура