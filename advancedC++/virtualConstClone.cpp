
#include <iostream>
#include <vector>

using namespace std;

class Dog
{
public:
	virtual Dog* clone(){cout << " dogclone " << endl;return (new Dog(*this));}	//co-variant return type
};

class YellowDog: public Dog
{
public:
	//co-variant return type provided YD is derived from dog
	virtual YellowDog* clone(){cout << " yellowDogclone " << endl;return (new YellowDog(*this));} 
};

void foo(Dog* d)	//'d' is a Yellowdog in this eg.
{
	//Dog* c = new Dog(*d);	//'c' is a dog
	Dog* c = d-> clone();
	//Use c
}

int main(void)
{
	YellowDog d;
	foo(&d);

	return 0;
}
