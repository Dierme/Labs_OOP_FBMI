#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int n, i, fib_one = 0, fib_two = 1, fib=0;
	cout << "Input n" << endl;
	cin >> n;
	for (i = 0; i > n; i++)
	{
		fib = fib_one + fib_two;
		fib_one = fib_two;
		fib_two = fib;
	}
	cout << fib << endl;
	_getch();
}