
#include <iostream>
#include <vector>

using namespace std;

/*
Logic constness -> What the user thinks is right logically

bitwise constness -> Does not change any of the members directly
					 Compiler uses this
*/

class bigArray
{
	vector<int>v; 	//huge vector
	mutable int accessCounter;	//Logic Constness - Use 'mutable'
	int* var;

public:
	int getItem(int index) const{ //Constant fns. cannot change member variables (unless they are 'mutable')
		
		//++accessCounter;
		//const_cast<bigArray*>(this)->accessCounter++;	//Hacky way

		return v[index];
	}

	int changeVar(int index, int x) const	//Compiles with const because bitwise constness works
	{
		*(var+index) = x;	//var doesn't change
	}
};

/*

const int* const fun(const int* const& p ) const

1. the return value of fun is a constant pointer pointing to a constant integer value
2. the parameter of fun is a reference of a constant pointer pointing to a constant integer
the reference cannot refer to a different pointer (nature of references)
the referred pointer cannot point to a different value
the pointed value of the referred pointer cannot be changed
3. fun is also a const function, meaning that it cannot directly modify members unless they are marked mutable, also it can only call other const functions﻿
*/

int main(void)
{
	bigArray b;

	return 0;
}

