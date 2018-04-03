
#include <iostream>
#include <vector>

using namespace std;

class Person{

public:
	Person(string name)	{ name_ = new string(name);}
	~Person(){ delete name_;}

	Person(const Person& rhs)	{ name_ = new string(*(rhs.name_)); }	//This is used implicitly at a lot of places
	/*Person& operator=(const Person& rhs){
		name_ = new string(*(rhs.name_)); 
	}*/

	// Person clone( )	{ return (new Person(*name_)); }	//This can used explicitly at a lot of places

	void printName(){ cout << *name_ << endl;}

private:
	string* name_;
};

//Soln. 1 - Define deep copy constructor and deep copy assignment operator
//Soln. 2 - Delete copy constructor and  copy assignment operator i.e. move to private

int main(void)
{
	vector<Person> persons;
	persons.push_back(Person("George"));
	// 1. George constructed 2. Shallow Copy of George is saved in persons. 3. George destroyed

	persons.back().printName();

	return 0;
}
