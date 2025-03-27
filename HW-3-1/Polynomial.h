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

	const Polynomial operator+(const Polynomial& polynomial) const;
	const Polynomial operator-(const Polynomial& polynomial) const;
	Polynomial& operator++();
	Polynomial operator++(int);
	Polynomial& operator--();
	Polynomial operator--(int);
	Polynomial& operator+=(Polynomial& polynomial);
	Polynomial& operator-=(Polynomial& polynomial);
	bool operator==(const Polynomial& polynomial) const;
	
};

ostream& operator<<(ostream& out, Polynomial& polynomial);