
#include <iostream>

using namespace std;


//Small passive objects that carry data. Few basic member fns.
struct Person_t{
	string name;		//public
	unsigned int age ;
};

// Bigger objs. interfaced through public member fns.
class Person{
	string name_;		//private
	unsigned int age_ ; //underscore if class data member - age_ (_age is used for global variable, _Age for internal implementation)

public:
	unsigned age() const { return age_;}	//getter, accessor. Change age_ variable name without changing the code in main
	void set_age(unsigned a){age_= a;}		//setter, mutator
};

/*
Structs are objects where the data/members themselves are the interface,
while classes use member functions as interface.

So, will your object be data-focused or function-focused?
That's what it's really about: Is it about organizing data, or about performing tasks
*/

int main(void)
{
	Person_t PT;
		cout << PT.age;

	Person P;
		cout << P.age();
		P.set_age(4);
	return 0;
}
