
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
#include <deque>
#include <condition_variable>

using namespace std;

deque<int> q; //integer deck
mutex mu;
condition_variable cond;

// PRODUCER
void fn_1()
{
	cout << " fn_1 " << endl;
	int count = 10;
	while(count > 0)
	{
		cout << " f1 count: " << count << endl;
		unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		cond.notify_one();	//Notify one waiting thread for this condition variable, if there is one
		// cond.notify_all(); Notify all threads waiting for this condition variable
		this_thread::sleep_for(chrono::seconds(1));	//Push no. and sleeps for 1 sec.
		count--;
	}
}

// CONSUMER
void fn_2()
{
	int data = 0;
	while(data != 1)
	{
		unique_lock<mutex> locker(mu);	//Only use unique lock not lock_guard for CV as we have do lock, unlock lot of times
		// Wait for condition variable
		// This will unlock the locker, go to sleep and wait after which it will lock again
		cond.wait(locker, [](){ return !q.empty(); });	//spurious wake can occur for cond. variable set for some other thread
														// so add another 'Q empty' condition

/*		OTHER SOLN. BY CHECKING Q EMPTY
		if(!q.empty())
		{*/
			data = q.back();
			q.pop_back();
			locker.unlock();	//We can do some computation which does involve q
			// Give up the lock before you use time for cout or anything else
			cout << " t2 got a value from t1: " << data << endl;
		// }

/*		OTHER SOLN.
		else
		{
			locker.unlock();
			// Sleep t2 so that it does not continously keep looping in the while loop
			// and keep locking, unlocking the mutex before t1 can even access it once
			// this_thread::sleep_for(chrono::seconds(1));  Finding the right time is difficult
		}*/
	}
}


int main(void)
{
	thread t1(fn_1);
	thread t2(fn_2);
	t1.join();
	t2.join();

	return 0;
}

