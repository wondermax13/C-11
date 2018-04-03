
#include <iostream>

using namespace std;

//Base class
class Dog
{
public:
	Dog() {
		cout << " Dog born " << endl;
		bark(); 				//If this is called from YDog constructor, it won't call the non-created YDog bark
	}							//But it will call Dog's bark. So this is not recommended

	virtual void bark(){cout << " Dog bark " << endl;}
	void seeCat(){ bark(); }
	~Dog(){cout << " Dog destroyed " << endl;}
};

//Inherited class
class YellowDog: public Dog
{
public:
	YellowDog(){cout << " YDog born " << endl;}
	virtual void bark(){cout << " YDog bark " << endl;}	//Dynamic binding calls yellow dog virtual fn.
	~YellowDog(){cout << " YDog destroyed " << endl;}
};


int main(void)
{
	YellowDog d;
	d.seeCat();

	return 0;
}

