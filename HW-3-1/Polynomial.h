#pragma once
#include <iostream>
#include <string>

using namespace std;
class Polynomial
{
private:
	int a0;
	int a1;
	int a2;

public:
	Polynomial();
	Polynomial(int a0, int a1, int a2);

	int getA0();
	int getA1();
	int getA2();

	void setA0(int a0);
	void setA1(int a1);
	void setA2(int a2);

	Polynomial operator+(const Polynomial& polynomial) const;
	Polynomial operator-(const Polynomial& polynomial) const;
	Polynomial operator+(int n) const;
	Polynomial operator-(int n) const;
	const Polynomial operator-() const;
	Polynomial& operator++();
	Polynomial operator++(int);
	Polynomial& operator--();
	Polynomial operator--(int);
	Polynomial& operator+=(const Polynomial& polynomial);
	Polynomial& operator-=(const Polynomial& polynomial);
	bool operator==(const Polynomial& polynomial) const;
	bool operator!=(const Polynomial& polynomial) const;
	Polynomial& operator=(const Polynomial& polynomial);
	int operator()(int x) const;
	// Можно перегрузить и другие, но логического обоснования для этого я не нашел
};

ostream& operator<<(ostream& out, Polynomial& polynomial);
istream& operator>>(istream& in, Polynomial& polynomial);