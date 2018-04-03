
#include <iostream>
using namespace std;

/*lvalue - object occupying identifiable location in memory (not just register)
int i = 4;	//i is lvalue
int*p = &i;
i = 2;		//Modifiable
*/

/*rvalue - Not an lvalue. Can't assign a different value to them

int x = 2; //2 is rvalue
x = i+2;	//i+2 is rvalue

int* p = &(i+2)	//Error since there is no address associated with (i+2)
i + 2 = 4       //Can't assign a different value to them

dog* d = new dog(); //dog() is rvalue
*/

/*
lvalue reference
int i;
int &r = i;
int &r = 5;		//Error
const int& r = 5; //Const lvalue reference assigned to rvalue (IMPORTANT)

int square(int& x) {}

int x = 5;
square(x); //OK
square(5); //Error since rvalue reference

Workaround -> int square(const int& x) {}
*/


/*lvalue to create rvalue
int i = 1;
int x = i;	//Implicit transform of lvalue 'i' to rvalue
*/


/*rvalue to create lvalue
int v[3];
*(v+2) = 4;	//Explicit transform of rvalue 'v+2'. Dereference of v+2 is lvalue
*/


/*Misconception 1 - fn. or operator always yields rvalue
int myglobal;

int& foo(){
	return myglobal;	//lvalue
}
foo() = 50;

array[3] = 50;	//[] always generates lvalue since it points to memory
*/


/*Misconception 2 - lvalues are always modifiable
const int myglobal = 1;
myglobal = 2;
*/

/*Misconception 3 - rvalues are always non-modifiable
class dog;
dog().bark();		//dog() is rvalue and bark() may change the state of dog
*/

int sqr(const int& x){cout << x*x << endl; return x*x;}

int main(void)
{
	int i = 5;
	sqr(i);
	sqr(40);	//Error if rvalue used with int& (i.e. sqr(int& x) { })

	return 0;
}

