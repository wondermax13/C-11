
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


int main(void)
{
	/*Thread*/
	std::thread t1(factorial, 6);
	std::this_thread::sleep_for(chronos::milliseconds(3));
	chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::milliseconds(4);
	std::this_thread::sleep_until(tp);

	/*Mutex*/
	std::mutex mu;
	std::lock_guard<mutex> locker(mu);
	std::unique_lock<mutex> ulocker(mu); //Lock, unlock multiple times
	ulocker.try_lock();
	ulocker.try_lock_for(chrono::nanoseconds(500));
	ulocker.try_lock_until(tp);

	/*Condn. Variable*/
	std::condition_variable cond;
	cond.wait_for(ulocker, chrono::milliseconds(400));
	cond.wait_until(ulocker, tp)

	/*Future and promise*/
	std::promise<int> p;
	std::future<int> f = p.get_future();
	f.get();
	f.wait();
	f.wait_for()
	f.wait_until()

	/*async*/
	std::future<int> f = async(factorial, 6);

	/*Packaged Task*/
	std::Packaged_task<int(int)> t(factorial);
	std::future<int> fu2 = t.get_future();
	t(6);

	return 0;
}

