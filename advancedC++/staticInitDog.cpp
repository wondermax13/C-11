
//Look at the example (no. 11 in advanced C++)

#include <iostream>

using namespace std;

/*
Dog.h
Dog class with name
*/

/*
Dog.cpp

Cat c("Smokey"); -> Global variable 1
void Dog::bark(){
	cout << " dog rules: name : " << _name << endl;
}

Dog::Dog(char* name ){
	cout << " construct dog : name	 : " << name << endl;
	_name = name;
	c.meow(); -> Being called on object that might not be constructed
				 Instead Use Singleton::getDog()->bark()
}
*/

/*
Cat.h
Cat class with name

Cat.cpp
Cat function to meow, cat constructor
*/

/*
Dog d("Gunner");  -> Global variable 1

int main() {
	
	d.bark(); //Use singleton
}

*/




//Use singleton pattern instead of global variables
//Here cat constructor references global Dog D ("DGlobal") and dog constructor references global C("CGlobal")
/*
Dog* singleton::pd = 0;
Cat* singleton::pd = 0;

Dog* singleton::getDog(){
	if(!pd)			//If pd not initialized
		pd = new Dog("DGlobal");
	return pd;
}

Cat* singleton::getCat(){
	if(!pc)			//If pc not initialized
		pc = new Cat("CGlobal");
	return pc;
}

singleton::~singleton(){
	if(pd) delete pd;
	if(pc) delete pc;
	pd = 0;
	pc = 0;

}
*/
