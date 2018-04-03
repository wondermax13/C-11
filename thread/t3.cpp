
#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>

using namespace std;

/*To avoid Data Race
1. Use mutex
2. Don't provide handle to outside
3. Design interface appropriately

*/


mutex mu;

void shared_print(string msg, int id)
{
	// mu.lock();					// Don't use mutex lock and unlock fns. directly as cout statement can throw exception
	lock_guard<mutex> guard(mu);	//RAII
	cout << msg << id << endl;
	// mu.unlock();
}

void f1()
{
	for(int i = 0 ; i> -10; i--)
		shared_print(" t1: ", i);
}

class LogFile
{
	mutex m_mutex;
	ofstream f;
public:
	LogFile(){
		f.open("log.txt");
	}
		;
	~LogFile(){
		f.close();
	}
	void shared_print(string id, int value)
	{
		lock_guard<mutex> locker(m_mutex);
		f << " From " << id << " : " << value << endl;	//Actual printing
	}

	// Never return f to outside world so user can get f without passing through mutex
	// Eg. LogFile.getF()

	// Never pass f as an argument to user defined fn.
	// Eg. void processF(void fun(ofstream& )){ fun(f) } //Here fun is the fn. ptr passed by the user

};

void f1_LogFile(LogFile& log)
{
	for(int i = 0 ; i> -10; i--)
		log.shared_print(" t1: ", i);
}

int main(void)
{
	LogFile log;

	thread t1(f1_LogFile, std::ref(log));	//starts running

	try{
		for(int i = 0 ; i< 10; i++){
			log.shared_print(" main: ", i);
			}
	}

	catch(...){
		t1.join();		//main waits for t1
		throw;
	}

	if(t1.joinable())
		t1.join();		//Can't join after detaching

	return 0;
}

