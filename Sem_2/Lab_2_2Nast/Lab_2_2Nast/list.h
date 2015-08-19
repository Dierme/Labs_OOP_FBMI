
#include "citizen.h"

class array_citizen{
private:
	citizen *Array;

public:
	array_citizen();
	array_citizen(int i);
	void findAge(int currentyear, int numofyears, citizen a);
	void findEducation(int  curreducation, citizen a);
	void findSex(int needsex, citizen a);
	void InitializeArray(int i);
	void setArrayCitizen(int pos, citizen ctz);
	void randomArrayFill(int pos);
	citizen array_citizen::getArrayCitizen(int pos);
	~array_citizen();
};
