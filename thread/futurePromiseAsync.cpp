
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

using namespace std;

mutex mu;
condition_variable cond;

int factorial(int N) //, int &x)
{
	int res = 1;
	for(int i = N; i>1; i--)
		res *= i;

	// x = res;
	cout << "Result : " << res << endl;

	return res;
}

int future_factorial(future<int>& f)
{
	int res = 1;

	//Can call get only once
	int N = f.get();   //exception: std:: future_error::broken_promise if promise.set_value not called

	for(int i = N; i>1; i--)
		res *= i;

	cout << "Result : " << res << endl;

	return res;
}


int main(void)
{
	int x = 0; //Shared variable between child and parent thread

	/*thread t1(factorial, 4, std::ref(x));  Other way but we need to keep condn. variable in this thread for x
	t1.join();*/

	future<int> fu1 = std::async(factorial,4); 
	x = fu1.get(); //Waits till child thread in async is finished. 
	// get() fn. can be called only once
	cout << " got from fu1 : " << x << endl;


	future<int> fu = std::async(std::launch::deferred, factorial,5); //Will execute thread only when fu.get() is called (Line 60)
	// future<int> fu = std::async(std::launch::async, factorial,4); Will create another thread
	// future<int> fu = std::async(std::launch::async | std::launch::deferred, factorial,4); //Will create another thread


    cout << " Before creating thread in async - deferred " << endl;
    x = fu.get();


    std::promise<int> p;
    future<int> f = p.get_future();
    future<int> f1 = std::async(std::launch::async, future_factorial, std::ref(f)); //Used for passing value from main to child

    //Do something before setting value
    cout << " Before seting value " << endl;

    p.set_exception(std::make_exception_ptr(std::runtime_error(" Value not set exception ")));
    // p.set_value(4);
    // x = f1.get();

    cout << " Got from child " << x << endl;

    //Move assigment with promise
    //std::promise<int> p2 = std::move(p);

    /*
    SHARED FUTURE -> IF YOU WANT TO PASS SAME FUTURE TO MANY CHILD THREADS
    shared_future_factorial() takes shared_future<int>

    	f = p.get_future();
		shared_future<int> sf = f.share();
		future<int> f1 = std::async(std::launch::async, shared_future_factorial, sf); //shared_future pass by value not reference
		future<int> f2 = std::async(std::launch::async, shared_future_factorial, sf); //shared_future pass by value not reference


    	 */

	return 0;
}

