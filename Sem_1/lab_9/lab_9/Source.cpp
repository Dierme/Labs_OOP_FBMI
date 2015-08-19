#include <iostream>
#include <cstdlib>

using namespace std;

void rec (int number)
{
	if (number >= 2)
		rec(number / 2);
	cout << number % 2;
	return;
}

int main()
{
	int number;
	cout << "Input the number" << endl;
	cin >> number;
	rec (number); 
	system("pause");
}

