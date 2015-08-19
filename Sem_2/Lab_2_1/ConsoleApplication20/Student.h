#pragma once
class Student
{
public:
	Student();
	Student(int*);
	Student(char*, char*, char*, char*, char*, char*, int, int*);
	~Student();
	void show_citizen(void);
	void set_Full_Name(char*);
	void set_Place_Of_birth(char*);
	void set_Adress(char*);
	void set_Date_Of_birth(char*);
	void set_Education(char*);
	void set_gender(char*);
	void set_age(int); 
	int get_age();
	int get_edu(); 
	int get_gender(); 
private:
	char *Full_Name;
	char *Place_Of_birth;
	char *Adress;
	char *Date_Of_birth;
	char *Education;
	char*gender;
	int age;
	int gender_size;
	int Adress_size;
	int Place_Of_birth_size;
	int Full_Name_size;
	int Education_size;
	int Date_Of_birth_size;
	int key;
};

