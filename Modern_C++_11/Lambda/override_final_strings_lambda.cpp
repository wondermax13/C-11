
#include <iostream>
#include <vector>

using namespace std;

/*
class baseClass
{
	virtual void function1(int);
	virtual void function2(int) const;
};

class childClass:baseClass
{
	//Created new function. Use override for compiler to give error if function does not exist in the baseClass
	virtual void function1(float) override;	  
	virtual void function2(int) override; //Created new function
};
*/

/*
class dog final		//No one can inherit from dog
{
	...
};

class dog
{
	dog(int a){}			//Compiler will not generate default constructor if you have already defined 1
	dog() = default;        //Force compiler to generate the default constructor
	virtual void bark() final;	//No one can override bark
};
*/

/*
dog a(2);
dog b (3.0);	//3.0 -> 3 (Implicit casting). We don't want to allow this.
a = b;		//We don't want to allow this assignment

So define these as deleted functions
dog(double) = delete;
dog& operator=(const dog&) = delete;
*/

/*
constexpr int A() { return 3;}	//Force the computation to happen at compile time. Tell it A() returns const int
int arr[A()+3];			//This will work. Otherwise compiler error

constexpr int cube(int x){ return x*x*x;}	//Force computation at compile time if we know that we alwas deal with const input
int y = cube(48); //Computed at compile time
*/

/*
String literals

//C++ 03
char* a = "string1";

//C++ 11
char* a = u8"string1";	UTF-18 string
char16_t* b = u"string1";	UTF-16 string
char32_t* c = U"string1";	UTF-32 strings
char* d = R"string1 \\";    raw string. Here '\\' is 2 slashes.
						   First '\' is not considered as an escape since defined as raw string

*/

//Lamda function
//cout << [](int x, int y){return x+y}(3,4) << endl;	//Output 7


template<typename func>
void filter(func f, vector<int> arr )
{
	for(auto i: arr)
	{
		if(f(i))
			cout << i << " " << endl;
	}
}

int main(void)
{
auto f = [](int x, int y) {return x+y;};
cout << f(3,4) << endl;

vector<int> v = {1,2,3,4,5};

//Function programming using lamda
filter( ( [](int x){return (x>3);} ), v);	//Here f ints [](int x){return (x>3);}

//Variable capture
int y =3;
filter([&](int x){return (x>y);}, v);	//Here f is return(x>3)
	return 0;
}

