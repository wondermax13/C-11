
#include <iostream>
#include <memory>
#include <string>

using namespace std;


class Dog {
	
public:
	Dog(string name) {

		cout << " Dog name: " << name << endl;
		name_ = name;
	}

	Dog() {
		cout << " Nameless Dog" << endl;
	}

	~Dog() {
		cout << " Dog destroyed: " << name_ << endl;
	}

	void bark() {
		cout << "Dog bark: " << name_ << endl;
	}

	string name_;
};

void foo() {
	
/*
	Failure case:

	Dog* p = new Dog("Gunner");

	delete p;

	p->bark(); //p is a dangling ptr, undefined behavior

	//If "delete p" not called, Memory leak
*/


	//reference count to know how many shared ptrs pointing to the object
	shared_ptr<Dog> p1(new Dog("Gunner")); //count = 1
	//Step 1. Gunner is created  Step 2. p1 is created

	{
		shared_ptr<Dog> p2 = p1; //count = 2

		p2->bark();

		cout << " sp count: " << p2.use_count() << endl;
	}

	p1->bark();
}



int main() {

	//foo();

/*
	//An object should be assigned to a smart pointer as soon as it is created

	//Raw ptr. should not be used
	Dog* d = new Dog("Tank");
	
	shared_ptr<Dog> p1(d); //p1.use_count()  = 1;
	shared_ptr<Dog> p2(d); //p2.use_count()  = 1;
*/

	//Shortcut of wrapping an object with sp
	shared_ptr<Dog> p = make_shared<Dog>("Tank"); //faster and safer (exception safe)

	(*p).bark();

	//static_pointer_cast
	//dynamic_pointer_cast
	//const_pointer_cast

	return 0;
}

