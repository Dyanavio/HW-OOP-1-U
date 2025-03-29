#include "Polynomial.h"
#include <iostream>
#include <string>

using namespace std;

Polynomial::Polynomial()
{
	a0 = 0;
	a1 = 0;
	a2 = 0;
}

Polynomial::Polynomial(int a0, int a1, int a2)
{
	this->a0 = a0;
	this->a1 = a1;
	this->a2 = a2;
}

int Polynomial::getA0()
{
	return a0;
}

int Polynomial::getA1()
{
	return a1;
}

int Polynomial::getA2()
{
	return a2;
}

void Polynomial::setA0(int a0)
{
	this->a0 = a0;
}

void Polynomial::setA1(int a1)
{
	this->a1 = a1;
}

void Polynomial::setA2(int a2)
{
	this->a2 = a2;
}

Polynomial Polynomial::operator+(const Polynomial& polynomial) const
{
	return Polynomial(a0 + polynomial.a0, a1 + polynomial.a1, a2 + polynomial.a2);
}

Polynomial Polynomial::operator-(const Polynomial& polynomial) const
{
	return Polynomial(a0 - polynomial.a0, a1 - polynomial.a1, a2 - polynomial.a2);
}

Polynomial Polynomial::operator+(int n) const
{
	return Polynomial(a0 + n, a1, a2);
}

Polynomial Polynomial::operator-(int n) const
{
	return Polynomial(a0 - n, a1, a2);
}

const Polynomial Polynomial::operator-() const
{
	return Polynomial(-a0, -a1, -a2);
}

Polynomial& Polynomial::operator++()
{
	a0++;
	a1++;
	a2++;
	return *this;
}

Polynomial Polynomial::operator++(int)
{
	Polynomial temp = *this;
	++*this;
	return temp;
}

Polynomial& Polynomial::operator--()
{
	a0--;
	a1--;
	a2--;
	return *this;
}

Polynomial Polynomial::operator--(int)
{
	Polynomial temp = *this;
	--*this;
	return temp;
}

Polynomial& Polynomial::operator+=(const Polynomial& polynomial)
{
	a0 += polynomial.a0;
	a1 += polynomial.a1;
	a2 += polynomial.a2;
	return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& polynomial)
{
	a0 -= polynomial.a0;
	a1 -= polynomial.a1;
	a2 -= polynomial.a2;
	return *this;
}

bool Polynomial::operator==(const Polynomial& polynomial) const
{
	if (a0 == polynomial.a0 && a1 == polynomial.a1 && a2 == polynomial.a2) return true;
	return false;
}

bool Polynomial::operator!=(const Polynomial& polynomial) const
{
	if (a0 != polynomial.a0 || a1 != polynomial.a1 || a2 != polynomial.a2) return true;
	return false;
}

Polynomial& Polynomial::operator=(const Polynomial& polynomial)
{
	if (this != &polynomial)
	{
		a0 = polynomial.a0;
		a1 = polynomial.a1;
		a2 = polynomial.a2;
	}
	return *this;
}

int Polynomial::operator()(int x) const
{
	return a2 * x * x + a1 * x + a0;
}

ostream& operator<<(ostream& out, Polynomial& polynomial)
{
	out << "(" << polynomial.getA2() << ")x^2 + (" << polynomial.getA1() << ")x + (" << polynomial.getA0() << ")";
	return out;
}

istream& operator>>(istream& in, Polynomial& polynomial)
{
	int a0, a1, a2;
	cout << "Enter a2: ";
	in >> a2;
	cout << "Enter a1: ";
	in >> a1;
	cout << "Enter a0: ";
	in >> a0;
	polynomial.setA2(a2);
	polynomial.setA1(a1);
	polynomial.setA0(a0);
	return in;
}
