#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

template <class user_class>
class Matrix
{
public:
	Matrix(int, int);
	Matrix(){};
	~Matrix();
	void show_matrix();
	void del();
	void rand_arr();
	bool empty();
	int get_rows() const;
	int get_collums() const;
	vector<vector<user_class>> get_matrix() const;
	bool find_elem(user_class, int*, int*);
	Matrix operator +(const Matrix&);
	Matrix operator -(const Matrix&);
	Matrix operator =(const Matrix &obj);
	friend ostream& operator<<<user_class>(ostream& os, const Matrix<user_class>& dt);
private:
	int collums;
	int rows;
	vector<vector<user_class>> imatrix;
};



template <class user_class>
Matrix<user_class>::Matrix(int collums_inp, int rows_inp)
{
	collums = collums_inp;
	rows = rows_inp;

	for (int i = 0; i < rows_inp; i++)
	{
		imatrix.push_back(vector<user_class>());
		for (int j = 0; j < collums_inp; j++)
			imatrix[i].push_back(rand() % 10);
	}
}


template <class user_class>
Matrix<user_class>::~Matrix()
{}


template <class user_class>
void Matrix<user_class>::show_matrix()
{
	std::for_each(imatrix.begin(), imatrix.end(), [](std::vector<user_class>& ivec)
	{
		std::for_each(ivec.begin(), ivec.end(), [](user_class i)
		{
			std::cout << std::left << std::setw(5) << i;
		});
		std::cout << std::endl;
	});
}


template <class user_class>
bool Matrix<user_class>::empty()
{
	return imatrix.empty();
}


template <class user_class>
int Matrix<user_class>::get_collums() const
{
	return collums;
}


template <class user_class>
int Matrix<user_class>::get_rows() const
{
	return rows;
}


template <class user_class>
vector<vector<user_class>> Matrix<user_class>::get_matrix() const
{
	return imatrix;
}


template <class user_class>
bool Matrix<user_class>::find_elem(user_class elem, int* coll_pl, int* row_pl)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
		if (imatrix[i][j] == elem)
		{
			*row_pl = i;
			*coll_pl = j;
			return true;
		}
	}
	return false;
}


template <class user_class>
Matrix<user_class> Matrix<user_class>::operator+(const Matrix<user_class>& right_m)
{
	int x = collums;
	int y = rows;
	Matrix result_m = *this;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
			result_m.imatrix[i][j] += right_m.imatrix[i][j];
	}
	return result_m;
}

template <class user_class>
Matrix<user_class> Matrix<user_class>::operator-(const Matrix<user_class>& right_m)
{
	int x = collums;
	int y = rows;
	Matrix<user_class> result_m = *this;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < collums; j++)
			result_m.imatrix[i][j] -= right_m.imatrix[i][j];
	}
	return result_m;
}


template <class user_class>
ostream& operator<<(ostream& os, const Matrix<user_class>& dt)
{
	int colums = dt.get_collums();
	int rows = dt.get_rows();
	vector<vector<user_class>> ptr_m = dt.get_matrix();
	for (int i = 0; i < colums; i++)
	{
		for (int j = 0; j < rows; j++)
			os << "[" << ptr_m[i][j] << "]";
		os << endl;
	}
	return os;
}