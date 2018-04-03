
#include <iostream>
#include <memory>

using namespace std;

//Base class
class Dog
{
public:
	~Dog(){cout << " Dog destroyed " << endl;}
};

//Inherited class
class YellowDog: public Dog
{
public:
	~YellowDog(){cout << " YDog destroyed " << endl;}
};

//Factory pattern
class DogFactory
{
public:
	//static Dog* createYellowDog(){ return (new(YellowDog));}
	//Or - 
	static shared_ptr<Dog> createYellowDog(){ 
		return shared_ptr<YellowDog>(new YellowDog());
	}
	//Unique pointer will only call dog destructor

	//...create other dogs
};

int main(void)
{
	//Dog* pd = DogFactory::createYellowDog();
	//Do something with pd
	//delete pd;	//Only dog destructor called if Dog* used and Dog has no virtual base destructor.
					//Not yellow dog destructor

	//Or - 
	// shared_ptr<Dog> pd = DogFactory::createYellowDog();	//No need for virtual destructor

	return 0;
}

