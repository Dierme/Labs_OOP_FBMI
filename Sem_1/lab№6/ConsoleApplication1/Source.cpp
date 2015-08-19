#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	int n, i, fib_one = 0, fib_two = 1, fib = 0;
	cout << "Input n" << endl;
	cin >> n;
	if (n == 1)
		cout << "fib(1) = 0" << endl;
	else if (n == 2)
		cout << "fib(2) = 1" << endl;
	else
	{
		for (i = 2; i < n; i++)
		{
			fib = fib_one + fib_two;
			fib_one = fib_two;
			fib_two = fib;
		}
		cout << "fib(" << n << ") = " << fib << endl;
	}
	
	_getch();
}