#include "Student.h"
#include "User_request.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vld.h>

using namespace std;

int main()
{
	int gender_choose, age_choose, choose, min_age, i = 0;

	srand(time(0));


	char *birth_place_st[] = { "Kyiv", "Zaporozhe", "Zhytimir", "Nikolaev", "Dnipropetrovsk", "Energodar", "Lviv" };
	char *birth_date_st[] = { "07.07.1995", "01.12.1995", "05.10.1995", "25.06.1996", "18.04,1996" };
	char *education_st[] = { "High", "Secondary" };
	char *adress_st[] = { "Metalistiv st.", "Voinov st.", "Kurchatova st.", "Pushkina st.", "Peremogu st." };
	char *full_name_st[] = { "Alex", "Oleksii",  "Nikita", "Evgenii", "Nastya","Tanua", "Sveta" };


	Student *array_of_objects;
	array_of_objects = new Student[10];
	for (int a = 0; a < 10; a++)
	{
		gender_choose = rand() % 6;
		if ((gender_choose == 0) || (gender_choose == 1) || (gender_choose == 2) || (gender_choose == 3))
			array_of_objects[a].set_gender("Male");
		else
			array_of_objects[a].set_gender("Female");

		age_choose = rand() % 4;
		if ((age_choose == 0) || (gender_choose == 1) || (gender_choose == 2))
			array_of_objects[a].set_age(19);
		else
			array_of_objects[a].set_age(18);

		array_of_objects[a].set_Full_Name(full_name_st[rand() % 6]);
		array_of_objects[a].set_Date_Of_birth(birth_date_st[rand() % 4]);
		array_of_objects[a].set_Adress(adress_st[rand() % 4]);
		array_of_objects[a].set_Education(education_st[rand() % 1]);
		array_of_objects[a].set_Place_Of_birth(birth_place_st[rand() % 6]);
	}
		
	User_request Request_1;
	cout << "Enter minimun age"; cin >> min_age;
	cout << "Citizens aged above" << min_age << ":" << endl;
	Request_1.Sort_by_age(array_of_objects, min_age);
	Request_1.High_edu_citz(array_of_objects);
	Request_1.Male_citz(array_of_objects);


	_getch();

}