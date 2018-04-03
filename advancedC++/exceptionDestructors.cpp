
#include <iostream>
#include <memory>

using namespace std;

//Base class
class Dog
{
public:
	string m_name;

	Dog(string name){m_name = name;}

	void bark(){};

	//Soln. 1 - Destructor swallows exception - If destructor handles the exception
	~Dog(){/*
		try{
		}
		//Enclose exception prone code here
		catch(MYEXCEPTION e){
		//catch exception
		}
		catch(...) {	//Generic exception
			
		}
		*/

		cout << " Dog destroyed " << endl;
	}

	//Soln. 2 - Move exception to different fn. - If client handles the exception
	void prepareToDestruct(){throw 20;}

};




int main(void)
{
	try{
		Dog dog1("Henry"); //If exception is thrown in Dog destructor then 2 exceptions thrown (1 for Henry, 1 for Bob)
		Dog dog2("Bob");
		//throw 20;	//- Before bark -> This can lead to 2 exceptions. 
				//20 will be caught by catch block
				//But stack will unwind inside try calling 2 destructors

		dog1.bark();
		dog2.bark();
		//dog1.prepareToDestruct();	//Not in destructor
		//dog2.prepareToDestruct();
	}
	catch(int e){
		cout << e << " is caught " << endl;
	}

	return 0;
}

