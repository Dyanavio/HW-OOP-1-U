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
