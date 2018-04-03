
#include <iostream>
#include <memory>
#include <string>

using namespace std;


//Unique ptr. -> Exclusive ownership, light weight smart pointer

class Dog {
	
public:
	//shared_ptr<Dog> m_pFriend;
	weak_ptr<Dog> m_pFriend; //weak_ptr has no ownership of the pointed object

	string m_name;
	void bark() { cout << " bark " << endl;}

	~Dog() {cout << " Destructor " << endl;}
};

void test() {

	/*
		Dog* pD = new Dog("Gunner");

		pD->bark();
		delete pD;  -> Not called if bark() throws exception
	*/

	unique_ptr<Dog> pD(new Dog("Gunner"));
	pD->bark();

	Dog* p = pD.release();
}

int main() {

	shared_ptr<Dog> pD(new Dog("Gunner"));
	shared_ptr<Dog> pD2(new Dog("Smokey"));

	pD->makeFriend(pD2);
	pD2->makeFriend(pD); //cylic reference -> Both shared_ptrs for pD and pD2 contain references to pD2 and pD respectively

	return 0;
}

