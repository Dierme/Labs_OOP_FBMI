#include <string.h>
#include <iostream>
#include<iostream>
using namespace std;

class citizen{
private:
	string Surname;
	string Name;
	string Middle_name;
	string Address;
	string Education;
	string  Sex;
	int Year_of_birth;
public:
	citizen(){};
	citizen(string OutSurname, string OutName, string OutMiddle_name, string OutAddress, string OutEducation, string OutSex, int OutYear_of_birth);
	void setSurname(string OutSurname);
	void setName(string OutName);
	void setMiddle_name(string OutMiddle_name);
	void setAddress(string OutAddress);
	void setEducation(string   OutEducation);
	void setYear_of_birth(int OutYear_of_birth);
	void setSex(string OutSex);
	string getSurname() const;
	string getName() const;
	string getMiddle_name() const;
	string getAddress() const;
	string getEducation() const;
	string  getSex() const;
	int getYear_of_birth()const;
	void Output();
	~citizen(){};
};


