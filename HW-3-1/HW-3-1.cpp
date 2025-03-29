#include <iostream>
#include <string>
#include "color.hpp"
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial polynomial1 = Polynomial(5, 10, 4);
	Polynomial polynomial2 = Polynomial(1, 2, 1);

	cout << dye::light_blue("First polynomial: ") << polynomial1 << endl;
	cout << dye::light_blue("Second polynomial: ") << polynomial2 << endl;

	cout << dye::green("\nEquality == operator: ") << (polynomial1 == polynomial2) << endl;
	cout << dye::green("Inequality != operator: ") << (polynomial1 != polynomial2) << endl;

	Polynomial polynomial3 = (polynomial1 + polynomial2);
	cout << dye::light_red("\nAdding two polynomials: ") << polynomial3 << endl;
	polynomial3 = (polynomial1 - polynomial2);
	cout << dye::aqua("Subtracting two polynomials: ") << polynomial3 << endl;

	polynomial3 = polynomial1 + 100;
	cout << dye::light_yellow("\nAdding an integer: ") << polynomial3 << endl;
	polynomial3 = polynomial1 - 200;
	cout << dye::yellow("Subtracting an integer: ") << polynomial3 << endl;

	polynomial3 = -polynomial2;
	cout << dye::light_blue("\nUnary minus to the second polynomial: ") << polynomial3 << endl;
	polynomial3++;
	++polynomial3;
	cout << dye::light_red("Applying increment twice for postfix and prefix forms: ") << polynomial3 << endl;
	polynomial3--;
	--polynomial3;
	cout << dye::aqua("Same for decrement: ") << polynomial3 << endl;

	polynomial3 += polynomial1;
	cout << dye::light_purple("\nPolynomial3 += Polynomial1") << polynomial3 << endl;
	polynomial3 -= polynomial2;
	cout << dye::purple("Polynomial3 -= Polynomial1") << polynomial3 << endl;

	cout << dye::bright_white("\nFunction call operator() - calculates polynomial value for x: ") << polynomial1(2) << endl;

}
