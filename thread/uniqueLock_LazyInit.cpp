
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

/*Unique lock is heavier than lock_guard*/

class LogFile
{
	mutex _mu;
	mutex _mu_fileOpen;
	ofstream _f;

	std::once_flag _flag;
public:
	LogFile(){
		// _f.open("log.txt");	//Open the file only if shared_print is called
	}
	~LogFile(){
		_f.close();
	}

	void shared_print(string id, int value)
	{
		// SOLUTION WITH ERROR
		/*if(!_f.is_open())	//Both is_open and open needs to be synchronized
		{
			// We can't use the same mutex for printing(which happens multiple times) and fileOpen(Once)
			unique_lock<mutex> locker2(_mu_fileOpen);
			// !!!Some other thread can access between these 2 statements and open the file again after checking it is not yet open.
			_f.open("log.txt");		//LAZY INIT or Initialization upon 1st use
		}*/

		// CORRECT SOLUTION
		//Calls open only once
		std::call_once(_flag, [&]{ _f.open("log.txt"); });

		// One way of locking mutex is lock_guard
		// lock_guard<mutex> locker(_mu, adopt_lock);	//Tells lock_guard that mutex is alredy locked and to unlock upon calling destructor

		// Unique_lock is more flexible. We can defer locking
		unique_lock<mutex> locker(_mu, defer_lock);
		// ... Stuff which does not require locking

		locker.lock();
		cout << " From p " << id << " : " << value << endl;
		locker.unlock();
		// ... Additional stuff which does not require locking

		// We can lock and unlock many times And even move the ownership
		// unique_lock<mutex> locker2 = move(locker);

	}
};

void f1_LogFile(LogFile& log)
{
	for(int i = 0 ; i> -100; i--)
		log.shared_print(" t1: ", i);
}

int main(void)
{
	LogFile log;

	thread t1(f1_LogFile, std::ref(log));	//starts running

		for(int i = 0 ; i< 100; i++)
			log.shared_print(" main  : ", i);


		t1.join();		//main waits for t1

	return 0;
}

