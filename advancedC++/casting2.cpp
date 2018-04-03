
//Explicit type conversion - Casting

#include <iostream>
#include <vector>

using namespace std;

class dog
{
public:
	dog(){};
	virtual ~dog(){cout << " dog destructor " << endl;}
	virtual void bark() { cout << " virtual bark " << endl;}	//Use polymorphism instead of casting
};

class yellowdog : public dog
{
	int age;
public:
	void bark(){cout << " yellowdog bark " << age << endl;}
};


int main(void)
{
	dog* pd = new dog();

	yellowdog* py = dynamic_cast<yellowdog*>(pd); //static cast here will not even fail on run-time but will just set age to 0
	//py->bark();		//Works for static fn. which does not access any member. Fail for non-static fn.

	//Better way would be to create virtual bark in dog. This will remove run-time identifier for bark, improving performance

	cout << " py = " << py << endl;		//output - 0. Output - address if static cast used
	cout << " pd = " << pd << endl;		//output - some address
	return 0;
}

