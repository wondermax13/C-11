
//Explicit type conversion - Casting

#include <iostream>
#include <vector>

using namespace std;

// 1. static_cast
/*
Between class hierarchy or types which have conversion fns. defined
	int i = 9;
	float f = static_cast<float> (i);
*/

// 2. dynamic_cast
/*
Only on pointers or references not objects
If casting fails output ptr = 0;
From base to derived
Requires 2 types to have polymorphic i.e. have atleast 1 virtual fn.
*/

// 3. const_cast
/*
Cast away const property;
Works on same type;
const char* str = " Hello";
char* modifiable = const_cast<char*>str;
*/

// 4. reinterpret_cast
/*
reinterpret bits of object pointed by p
Works on any type but ptrs. or references;
long p = 374342794;
dog*dd = reinterpret_cast<dog*>(p);
*/

int main(void)
{


	return 0;
}
