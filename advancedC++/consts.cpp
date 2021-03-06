
#include<iostream>
#include<string>

using namespace std;

class Dog
{
	int age;
	string name;
public:
	Dog(){age = 3; name = "dummy";}

	//Const parameters with copy(not with reference)
	//void setAge(const int a){age = a;}	//Can't change a. Also const & widely used in C++
//	void setAge(int a){age = a;}	//Can't change a

	//Const parameters with reference
	void setAge(const int& a){age = a; cout << " const int &" << endl;}	//Can't change a. Also const & widely used in C++
	void setAge(int& a){age = a; cout << " int &" << endl;}	//Can change a


	//Const return values
	const string& getName(void){return name;}	//caller can't change name
//	const string getName(void){return name;}	//no use of const

	//Const function
	//This fn. invoked when dog is const
	void printName() const 	{cout << name << " con" << endl;} //This function can't change member variables. It can't call another fn.
	void printName() {cout << name << endl;}	//This function can be used on non-const dog class
};




int main(void)
{
	const int i = 9;
	//i = 6; not allowed
	//const_cast<int &>(i) = 6;	//Allowed


	int j;
//	static_cast<const int &>(j) = 7;	//Not allowed

	const int *p1 = &i;	//data is const(const int) ptr is not
	//++p1; Allowed

//	int* const p2;		//Ptr is const (const p2)

//	const int* const p3;	//Both const

	Dog d;	
	const string& n = d.getName();	//Can't change n
	const int constInt = 3;
	int Int = 3;
	d.setAge(Int);

	const Dog dconst;
	dconst.printName();

	return 0;
}




