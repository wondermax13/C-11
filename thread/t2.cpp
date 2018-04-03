
#include <iostream>
#include <thread>
using namespace std;

void f1()
{
	cout << " f1 output " << endl;
			for(int i = 0 ; i> -10; i--)
			cout << " " << i << endl;
}

class Fctor
{
public:
	void operator()(string& msg)
	{
		for(int i = 0 ; i> -10; i--)
			cout << msg << " " << i << endl;
		msg = " hey ";
	}
};

int main(void)
{
	// thread t1(f1);	//starts running
	string s = " hi ";
	cout << " main id " << this_thread::get_id() << endl;

	// Fctor fct(s);
	// thread t1(fct);
	// thread t1( Fctor(), s);		//Parameter to thread is always passed by value
	thread t1( (Fctor()), std::ref(s));		//Parameter to thread is always passed by value

	cout << " t1 id " << t1.get_id() << endl;
	// thread t2 = std::move(t1);

	//using RAII wrapper w(t1)

	cout << " " << thread::hardware_concurrency() << endl;	//Indication - cpu

	try{
		for(int i = 0 ; i< 10; i++)
			cout << " main " << i << endl;
	}

	catch(...){
		t1.join();		//main waits for t1		
		throw;
	}

	// t1.detach();	//daemon process

	if(t1.joinable())
		t1.join();		//Can't join after detaching
	
	cout << s << " new value " << endl;
	return 0;
}


