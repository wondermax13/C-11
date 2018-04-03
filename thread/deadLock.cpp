
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;


/*To avoid deadlock
1. Lock m1 then do some stuff then lock m2
2. Lock m1 then call user fn. which could possibly lock m2
3. Use std::lock
4. Lock mutex in same order

If locks are too fine grained then deadlock has higher chance - Less data
				 coarse grained then many threads will wait for resource - More data
 */

class LogFile
{
	mutex _mu;	//Security
	mutex _mu2; //Filesytem
	ofstream _f;
public:
	LogFile(){
		_f.open("log.txt");
	}
	~LogFile(){
		_f.close();
	}

	void shared_print(string id, int value)
	{
		lock(_mu, _mu2);	//Lock both at the same time
		lock_guard<mutex> locker(_mu, adopt_lock);	//Tells lock_guard that mutex is alredy locked and to unlock upon calling destructor
		lock_guard<mutex> locker2(_mu2, adopt_lock);
		cout << " From p " << id << " : " << value << endl;
	}

	void shared_print2(string id, int value)
	{
		lock_guard<mutex> locker2(_mu2, adopt_lock);
		lock_guard<mutex> locker(_mu, adopt_lock);
		cout << " From p2 " << id << " : " << value << endl;
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
			log.shared_print2(" main  : ", i);


		t1.join();		//main waits for t1

	return 0;
}

