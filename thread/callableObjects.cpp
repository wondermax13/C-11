
#include <iostream>
#include <thread>
#include <mutex>
#include <deque>
#include <condition_variable>
#include <future>

using namespace std;

mutex mu;
condition_variable cond;

class A
{
public:
	void f(int x, char c){}
	long g(double x){ return 0;}
	int operator()(int N){ return 0;}
};

void foo(int x){}

int main(void)
{
	A a;
	/* Callable Objects examples
	async(std::launch::async, a, 6);
	std::bind(a, 6);
	std::call_once(once_flag, a, 6);*/

	thread t1(a, 6);            //copy_of_a() in a different thread
	thread t2( std::ref(a), 6); //a() in a different thread
    thread t3( A(), 6);         //temp A in a different thread
    thread t4( [] int x{return x*x;}, 6 );
    thread t5( foo, 7 );
    thread t6( &A::f, a, 8, 'w' ); //copy_of_a.f(8, w) in a different thread
    thread t7( &A::f, &a, 8, 'w' ); //a.f(8, w) in a different thread
    thread t8( &A::f, move(a), 6 ); // a is no longer usable in main thread as it has been moved to child thread

	return 0;
}

