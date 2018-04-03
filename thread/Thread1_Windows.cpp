
#include <iostream>
#include <thread>

using namespace std;

void function_1()
{
	cout << " sample message " << endl;
}

int main()
{
	thread t1(function_1);
	//t1.join();		//main waits for t1 to finish
	t1.detach();		//t1 will run on its own...daemon process

	if(t1.joinable())
		t1.join();		//Does not crash


	return 0;
}

