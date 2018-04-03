
#include<iostream>
#include<mutex>

using namespace std;

//Eg. 1
Mutext_t mu = MUTEX_INITIALIZER;

void functionA()
{
	Mutext_lock(&mu);
	Mutext_unlock(&mu);	//Might not be executed always
}

//Soln.
class Lock {

public:
	//constructor -> lock mutex
	//destructor -> unlock mutex

private:
	Mutext mu;
};

//Eg. 2
/*
train(tr1::shared_ptr<dog>(new dog()), getTrick());

Here compiler determines the order of 
new dog()
getTrick() //Might throw exception leaving new dog() behind
Construct tr1::shared_ptr<dog>()

So solution is
tr1::shared_ptr<dog> pd( new dog())
train(pd, getTrick())
*/

//Eg.3
/*
	Mutex is mutually exclusive. So can't be shared my mutiple classes
	Lock L1(&mu);
	Lock L2(L2);	//Prohibit this

	Soln. 1 -> Prohibit copy constructor and assignment in Lock

	Soln. 2 -> shared ptr. specifying a deleter fn.

	class Lock {

	public:
		//constructor -> lock mutex i.e.
		
		Lock(Mutex_t *pm) : pMutex(pm, Mutex_unlock) {
			Mutex_lock(pm);
		}
		//destructor -> unlock mutex

	private:
		std::tr1::shared_ptr<Mutex_t> pMutex;
};

*/


int main(void)
{
	return 0;
}


