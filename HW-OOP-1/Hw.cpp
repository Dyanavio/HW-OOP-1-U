#include <iostream>
#include <cmath>
#include <iomanip>
#include "color.hpp"
using namespace std;

class Matrice
{
private:
	int n;
	int m;
	int** ptr;

public:
	Matrice() : ptr(NULL)
	{
		n = 0;
		m = 0;
	}
	Matrice(int n, int m)
	{
		this->n = n;
		this->m = m;

		ptr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			ptr[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->ptr[i][j] = 0;
			}
		}
	}
	Matrice(int n, int m, int**p)
	{
		this->n = n;
		this->m = m;

		this->ptr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			ptr[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				this->ptr[i][j] = p[i][j];
			}
		}
	}
	~Matrice()
	{
		for (int i = 0; i < n; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
		//cout << dye::red("Destructor is called") << endl;
	}
	bool isZero()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (ptr[i][j] != 0) return false;
			}
		}
		return true;
	}
	double getNorm()
	{
		double sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sum += ptr[i][j] * ptr[i][j];
			}
		}
		return sqrt(sum);
	}
	Matrice add(const Matrice& a)
	{
		Matrice c = Matrice(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				c.ptr[i][j] += ptr[i][j] + a.ptr[i][j];
			}
		}
		return c;
	}
	string toString()
	{
		string str = "";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				str += to_string(ptr[i][j]) + "; ";
			}
			str.append("\n");
		}
		return str;
	}
	const Matrice operator+(const Matrice& matrice)
	{
		Matrice c = Matrice(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				c.ptr[i][j] = ptr[i][j] + matrice.ptr[i][j];
			}
		}
		return c;
	}
	const Matrice operator-(const Matrice& matrice)
	{
		Matrice c = Matrice(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				c.ptr[i][j] = ptr[i][j] - matrice.ptr[i][j];
			}
		}
		return c;
	}
	const Matrice operator*(int a)
	{
		Matrice c = Matrice(n, m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				c.ptr[i][j] = ptr[i][j] * a;
			}
		}
		return c;
	}
};

void InitialiseDoubleArray(int n, int m, int** ptr)
{
	//ptr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		ptr[i] = new int[m];
	}
}
void FillDoubleArray(int n, int m, int ** ptr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			ptr[i][j] = rand() % 100;
		}
	}
}


int main()
{
	srand(time(NULL));
	int n = 2;
	int m = 2;
	int q = 5;
	int** ptr = new int*[n];
	InitialiseDoubleArray(n, m, ptr);
	FillDoubleArray(n, m, ptr);

	Matrice a = Matrice(n, m, ptr);
	cout << dye::green("Matrice A:\n") << a.toString();
	cout << "Is zero: " << a.isZero() << endl;
	cout << "Norm: " << a.getNorm() << endl << endl;

	FillDoubleArray(n, m, ptr);
	Matrice b = Matrice(n, m, ptr);
	cout << dye::green("Matrice B:\n") << b.toString() << endl;

	Matrice c = a + b;
	cout << dye::yellow("Addition of A + B:\n") << c.toString() << endl;
	Matrice d = a - b;
	cout << dye::yellow("Subtraction of A - B:\n") << d.toString() << endl;

	Matrice f = a * q;
	cout << dye::light_red("New matrice A * a constant:\n") << f.toString() << endl;

	Matrice e = Matrice(n, m);
	cout << dye::light_blue("Zero matrice: \n") << e.toString();
	cout << "IsZero method: " << e.isZero() << endl;

}
