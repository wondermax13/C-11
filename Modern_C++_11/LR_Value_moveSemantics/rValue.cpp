
#include <iostream>

using namespace std;

//C++ 11 Rvalue reference


/*1*/ void printI(int& i){ cout << " lvalue ref: " << i << endl;}
/*2*/ void printI(int&& i){ cout << " rvalue ref: " << i << endl;}

//This 3rd function overloading will confuse the compiler for both the cases
// printI(a) -> 1 or 3 ?
// printI(6) -> 2 or 3 ?
//void printI(int i){ cout << " normal int: " << i << endl;}

//Rvalues are useful with resource managing objects

class boVector
{
	int size;
	double* arr_;	//A big array

public:
	boVector(){ size = 0;}

	boVector(const boVector& rhs)	//Copy constructor
	{
		size = rhs.size;
		arr_ = new double[size];

		for(int i=0; i<size; i++) {

			arr_[i] = rhs.arr_[i];
		}
	}

	boVector(boVector&& rhs)	//Move constructor
	{				//This constructor is making an in-expensive shallow copy
		size = rhs.size;
		arr_ = rhs.arr_;
		rhs.arr_ = nullptr; //Important otherwise destructor of rhs arr_ will delete this array
	}

	~boVector(){
		delete arr_;
	}
};

boVector createBoVector(void){

	boVector v;
	return v;
}

int foo(boVector v){ return 0; }; //return v.size;

int main(void)
{
	int a = 5;	//lvalue
	int& b = a;	//lvalue reference

	//int &&c; 	//rvalue reference

	printI(a);
	printI(6);

	boVector reusable = createBoVector();
	//foo(reusable);		//lvalue reference. this function will do a deep copy to create reusable and then use that copy
	//foo(createBoVector())		//rvalue. so move constructor called. If no move constr. defined temporary created and then destroyed

	/*  The other option is to specify 2 different foo fns.
		foo_by_value(boVector v) -> foo_by_value(reusable)
		foo_by_ref(boVector& v)  -> foo_by_ref(createBoVector())
	*/

	/* In cases where reusable destroyed after using for foo
	   and
	   we don't wish to make a copy of reusable

	   We can do 
	   -> Use move function to move reusable object to foo,
	      calling boVector(boVector&& rhs) So  //MOVE CONSTRUCTOR - 2ND FASTEST

	   foo(std::move(non-reusable)); //non-reusable.arr_ = nullptr in foo(boVector&& v), Destructor called on non-reusable

	   Eg. - foo(booVector&& v)
	*/
	/*
	   foo_by_ref(reusable)		//Call by reference - FASTEST
	   Eg. - foo(booVector& v)
	*/
	/*
	   boVector(boVector&& rhs) So  //MOVE CONSTRUCTOR - 2ND FASTEST
	*/
	/*
		SLOWEST - Copy constructor
		foo(reusble)
		Eg. - foo(booVector v)
	*/


	//Use cases for rvalue reference
	//Overloading copy constructor/ assignment operator with move ../..
	//Used in resource managing objects
	//Main purpose of move constructor/assignment -> Avoid costly and unnecessary deep copying

	/*

	1) Overload copy constructor and copy assignment operator to acheive move semantics

	//OVERLOADING COPY ASSIGNMENT OPERATOR
	X& X::operator=(X const & rhs);
	X& X::operator=(X && rhs); -> Overloaded using move assignment operator to acheive  move semantics


	//C++-11 already has move semantics. So pass-by-value can be used for STL containers
	vector<int> foo()
	{ return myVector;} //Even if myVector is huge, this is fine since move semantics uses move constructor

	void hoo(string s)

	bool goo(vector<int> & arg)	//Pass by reference if you use arg to carry data back from goo
	*/

	//CONCLUSION - WITH STL, USE MOVE SEMANTICS IN CASES WHERE YOU PASS BY VALUE NOT WHERE YOU PASS BY REFERENCE

	return 0;
}

/*
	//PERFECT FORWARDINGS

void foo(boVector arg)	//boVector has both move constructor and copy constructor

template<typename T>
void relay(T arg)
{
	foo(arg);	//Requirements -> rvalue should be forwarded as rvalue, lvalue should be forwarded as lvalue
}

relay(reusable);
relay(createBoVector());

2 main points to be considered
i) No unnecessary copy construction
ii) rvalue should be forwarded as rvalue, lvalue should be forwarded as lvalue



//SOLUTION
template<typename T>
void relay(T && arg)
{
	foo(std::forward<T>( arg )); //Solution
}


	T& &   => T&
	T& &&  => T&
	T&& &  => T&
	T&& && => T&&

template<...>
struct remove_reference

//T is int&
remove_reference<int&>::type i	//int i;
remove_reference<int>::type i	//int i;

void relay(T&& arg)	//Universal value (Can take on lvalue, rvalue, const, non-const)

relay(9)  T = int&& => T&& = int&& && = int&&
relay(x)   T = int& => T&& = int& && = int&

Here T&& is a universal reference only if 
i) T is a template type (not a regular type like int or double)
ii) Reference collapsing happens on T
    So T should be a function template type not a class template type (Eg. int, double)s


//Implementation of std::forward()

template<typename T>
void relay(T&& arg)
{
	foo(std::forward<T>(arg));
}

//Relay function cast arg to the type of T&& and passes that to foo
//It takes universal value input (i.e. T&&)
//So if arg is lvalue, foo gets lvalue arg, rvalue ,

template<typename T>
T&& forward(typename remove_reference<T>::type & arg)
	return static_cast<T&&>arg;

*/
/*
	move<T>arg	//Typecast into rvalue type
	forward<T>arg	//Typecast into T&& type
*/



