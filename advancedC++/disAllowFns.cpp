
#include <iostream>

using namespace std;

class openFile
{
public:
	openFile(string filename){cout << fileName << endl;} //In a way disallowing default constructor

	//destroyMe(){delete this;}	//Use this as destructor in case of private destructor

	//C++ 11 
	openFile(openFile& rhs) = delete; //Disallow copy constr. using a deleted fn.

	//C++03
	//private:
		//copy constructor
	//private: 
		//destructor		//Declare on heap not on stack

};

int main(void)
{
	openFile f1(string("Bo_File"));

	openFile f2(f1);	//We want to prevent both files writing to the same file

	//openFile* f1(string())	//This is on heap so will not call destructor
	//f1->destroyMe()
}

