
#include <iostream>

using namespace std;

/*
Everyone knows how to use the Polymorphism with dynamic binding. But dynamic binding has a run-time cost of both time and memory (virtual table)
*/

/* Soln. 1
class baseClass
{
public:
	virtual void callBark(){cout << " baseBark " << endl;}

private:
	
};

class derivedClass : public baseClass
{
public:
	void callBark(){cout << " derivedBark " << endl;}

private:
	
};*/

//Curiously recurring template(CRTP) pattern or static, simulated polymorphism
// Eg. of template metaprogramming
template<typename T>
class baseClass
{
public:
	void callBark() { static_cast<T*>(this)->callBark(); }	//No polymorphism but call depends upon template 'T'
															//This will do compile time lookup for derivedClass and call its callBark()
};

class derivedClass : public baseClass<derivedClass>
{
public:
	void callBark(){cout << " derivedBark " << endl;}

};


int main(void)
{
	derivedClass dc;
	dc.callBark();

	return 0;
}

