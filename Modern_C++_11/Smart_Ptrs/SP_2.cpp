
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
	
	shared_ptr<Dog> p1 = make_shared<Dog>("Gunner"); //using default deleter: operator delete

	//Gunner is deleted in any of these situations
	p1 = p2;
	p1 = nullptr;
	p1.reset();

	shared_ptr<Dog> p2 = shared_ptr<Dog>(new Dog("Tank",
		[](Dog* p) {

			cout << "Custom deleting. "; delete p;

		}));

	shared_ptr<Dog> p3(new Dog[3]); //Dog[1] and Dog[2] leaked

	shared_ptr<Dog> p4(new Dog[3], [](Dog* p) { delete[] p;}); //All 3 dogs deleted

}

void fooGet() {

	shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
	Dog* d = p1.get();

	delete d; //Don't use raw ptrs like this
}



int main() {

	return 0;
}

