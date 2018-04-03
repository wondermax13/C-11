
#include <iostream>
#include <thread>
using namespace std;

void f1()
{
	cout << " f1 output " << endl;
}

int main(void)
{
	thread t1(f1);	//starts running
	t1.join();		//main waits for t1
	// t1.detach();	//daemon process

	// if(t1.joinable())
		// t1.join();		//Can't join after detaching
	

	return 0;
}

