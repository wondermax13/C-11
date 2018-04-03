
#include <iostream>

using namespace std;

class dog
{
public:
	void bark() { cout << " dog " << endl;}
};

class yellowdog : public dog
{
public:
	void bark() { cout << " yellowdog " << endl;}
};

int main(void)
{
	yellowdog* py = new yellowdog();
	py->bark();

	dog* pd = py;
	pd->bark();		//output - dog. Same object reacts through the same API is behaving differently

/*Polymorphism
Different classes of objects react through same API will behave differently

Here - Same object behave differently

1)So never override non-virtual fn.
2) Never override default parameter value for virtual fns. eg. virtual void bark(string msg = "default value")
3) Force inheritance of shadowed fns. eg. using dog::bark() for using the fn. void bark(int age) present inside the dog
*/

	return 0;
}
