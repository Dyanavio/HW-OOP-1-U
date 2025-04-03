#include <iostream>
#include "color.hpp"

using namespace std;

template <typename T>
class Matrix
{
protected:
	T** a;
	int size1;
	int size2; //Что они делали в public?

public:
	Matrix(int n, int m) : size1(n), size2(m) 
	{
		try
		{
			a = new T * [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new T[m];
			}
		}
		catch (exception e)
		{
			cout << dye::red("Exception: " + string(e.what())) << endl;;
		}
	}
	Matrix()
	{
		size1 = 1;
		size2 = 1;
		a = new T * [1];
		a[0] = new T[1];
	}
	~Matrix()
	{
		for (int i = 0; i < size1; i++)
		{
			delete a[i];
		}
		delete[] a;
		//cout << "Destructor" << endl;
	}

	int getSize1() { return size1; }
	int getSize2() { return size2; }

	T* operator [](const int i) { return a[i]; }

	Matrix operator+(const Matrix& lhs) const 
	{
		Matrix c(size1, size2);
		for (int i = 0; i < size1; i++) 
		{
			for (int j = 0; j < size2; j++) 
			{
				c.a[i][j] = a[i][j] + lhs.a[i][j];
			}
		}
		return c;
	}
	Matrix operator-(const Matrix& lhs) const
	{
		Matrix c = Matrix(size1, size2);
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				c.a[i][j] = a[i][j] - lhs.a[i][j];
			}
		}
		return c;
	}
	Matrix operator*(const int a) const
	{
		Matrix c = Matrix(size1, size2);
		for (int i = 0; i < size1; i++)
		{
			for (int j = 0; j < size2; j++)
			{
				c.a[i][j] = this->a[i][j] * a;
			}
		}
		return c;
	}
	Matrix operator*(const Matrix& lhs)
	{
		try
		{
			if (size2 != lhs.size1)
			{
				throw std::exception("Invalid sizes");
			}
			Matrix c = Matrix(size1, lhs.size2);
			for (int i = 0; i < size1; i++)
			{
				for (int j = 0; j < lhs.size2; j++)
				{
					c[i][j] = 0;
					for (int k = 0; k < size2; k++)
					{
						c.a[i][j] += a[i][k] * lhs.a[k][j];
					}
				}
			}
			return c;
		}
		catch (exception e)
		{
			cout << dye::red("Exception: " + string(e.what())) << endl;
		}
		
	}
	static friend ostream& operator<< (ostream& os, const Matrix& a)
	{
		//	  countT++;
		for (int i = 0; i < a.size1; i++) 
		{
			for (int j = 0; j < a.size2; j++) 
			{
				os << a.a[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
	static friend istream& operator>> (istream& is, const Matrix& a) 
	{
		//	  countT++;
		for (int i = 0; i < a.size1; i++)
		{
			for (int j = 0; j < a.size2; j++) 
			{
				cout << "Enter value(" << i << ", " << j << "): ";
				is >> a.a[i][j];
			}
		}
		return is;
	}
	Matrix& operator=(const Matrix& a)
	{
		if (this != &a)
		{
			size1 = a.size1;
			size2 = a.size2;
			for (int i = 0; i < size1; i++)
			{
				for (int j = 0; j < size2; j++)
				{
					this->a[i][j] = a.a[i][j];
				}
			}
		}
		return *this;
	}
};

template<typename T>
class SquaredMatrix : public Matrix<T>
{
public:
	SquaredMatrix(int n) : Matrix<T>(n, n) {};
	SquaredMatrix() : Matrix<T>() {};

	T trace()
	{
		T tr = 1;
		for (int i = 0; i < this->size1; i++)
		{
			tr *= this->a[i][i];
		}
		return tr;
	}
};

int main(void)
{
	cout << dye::yellow("--- Matrice A ---") << endl;
	Matrix<double> a(2, 2);
	cin >> a;
	cout << a;

	cout << dye::green("--- Matrice B ---") << endl;
	Matrix<double> b(2, 2);
	cin >> b; 
	cout << b << endl;

	cout << dye::aqua("--- Matrice C ---") << endl;
	Matrix<double> c(2, 2);
	c = a + b;
	cout << c;

	cout << dye::blue("--- Matrice D ---") << endl;
	Matrix<double> d(2, 2);
	d = a - b;
	cout << d;

	cout << dye::light_aqua("--- Matrice C * 5 ---") << endl;
	cout << (c * 5) << endl;

	cout << dye::light_purple("--- Matrice E ---") << endl;
	SquaredMatrix<double> e = SquaredMatrix<double>(2);
	cin >> e;
	cout << e;
	cout << dye::light_red("E trace: ") << e.trace() << endl;

	cout << dye::light_blue("--- Matrice F ---") << endl;
	Matrix<double> f = a * b;
	cout << f;

}
