
#include <iostream>

using namespace std;


//Member variable
class collar;

class Dog
{
	collar* pCollar;
	dog& operator=(const dog& rhs)
	{
		if(this==rhs)
			return this;

		//delete pCollar;
		//Soln. 1
		collar* backupCollar = pCollar;
		pCollar = new collar(*rhs.pCollar);	//What if rhs.pCollar throws in exception. this->collar is already deleted
		//Soln1
		delete backupCollar;			//This doesn't get executed if exception thrown

		return *this;
	}

	//Soln. 2 - Here we have removed the if statement
	/*
	dog& operator=(const dog& rhs)
	{
		*pCollar = *rhs.pCollar;	//If this = rhs we are just self-assignment
		return *this;
	}
	*/

};


int main(void)
{
	return 0;
}

