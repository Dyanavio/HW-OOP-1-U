#include <iostream>
using namespace std;

template<typename T>
T findSum(T a, T b)
{
	return a + b;
}

int main()
{
	string s1 = "Hello ";
	string s2 = "there";
	cout << "Int: " << findSum(15, 20) << endl;
	cout << "Double: " << findSum(15.5, 20.8) << endl;
	cout << "String: " << findSum(s1, s2) << endl;
}
