
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <deque>

using namespace std;

/*
3 Ways to get Future
Promise
Async
Packaged_task - Can link callable object to future
*/

/*Fn. object
auto t = bind(factorial, 6)
*/

int factorial(int N)
{
	int res = 1;
	for(int i = N; i>1; i--)
		res *= i;

	cout << "Result : " << res << endl;

	return res;
}

std::deque<std::packaged_task<int()> > task_q;
mutex mu;
condition_variable cond;

void thread_1()
{
	std::packaged_task<int()> t;
	{
		std::unique_lock<mutex> locker(mu); //Use mutex because you are using task_q in child and main thread
		cond.wait(locker, [](){return !task_q.empty();} );
		t = std::move(task_q.front());
		task_q.pop_front();
	}

	t();    //This is where the originial factorial(6) is called

}


int main(void)
{
	cout << " before thread 1 " << endl;
	std::thread t1(thread_1);

	//t is a task being packaged up and this packaged can transferred to different object
	// (1) std::packaged_task<int(int)> t(factorial); //Cannot pass additional parameter in t constructor
    std::packaged_task<int()> t( std::bind(factorial, 6) ); //Bind 6 to fn. object which then passed to t
    //...
    //  (1) t(6); //In a different context
    // t();       //Initialized in future

     cout << " after main packaged task " << endl;
    std::future<int> fu = t.get_future();
	{
		std::lock_guard<mutex> locker(mu); //Use mutex because you are using task_q in child and main thread
		task_q.push_back(std::move(t));    //Use move because t is not used in the main thread after push_back
	}
	cond.notify_one();

    cout << fu.get();
	cout << " before t1 join " << endl;

    t1.join();

    // int x = t.get_future().get(); Get value from packaged_task

	return 0;
}

