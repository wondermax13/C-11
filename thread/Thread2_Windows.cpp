
#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	cout << " sample message " << endl;
}

class Fctor
{
public:
	void operator()(string &s)
	{		
		s = "string changed inside t1 ";
		cout << " from t1: s is " << s[0] << endl;
	}


};


int main()
{
	Fctor fct;
	string s = "Original string ";
	thread t1( (Fctor()), s);		

	//thread t1(function_1);		//t1 starts

	//using RAII
	// Wrapper w(t1)		//Destructor calls t1.join()


	//Catch main exception. In that case we should still join t1 as program might crash otherwise
	try{
		for(int i = 0; i<100; i++)
			cout << " from main: " << i << endl;
	}
	catch(...)
	{
		t1.join();
		throw;
	}

	t1.join();		//Default joining of t1 if no exception occurs

	return 0;
}


