#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include "Matrix.h"
#include <ctime>
using namespace std;
int main()
{
	srand(time(NULL));
	Matrix<int> im(4, 4);
	im.show_matrix();
	bool t; int x = 0, y = 0, search = 5;
	t = im.find_elem(search, &x, &y);
	if (t)
		cout << "Element (" << search << ") found. [" << y + 1 << "|" << x + 1 << "]" << endl;
	else
		cout << "Element not found" << endl;

	Matrix<int> im_1(4, 4);
	cout << im_1-im;

	system("pause");

}