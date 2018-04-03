
#include <vector>
#include <string>
#include <iostream>
#include <initializer_list>
using namespace std;

int arr[4] = {3, 2, 4 ,5};

// { } is uniform initialization

//vector<int> v{3, 2, 4 ,5}; - 2nd choice
//vector<int> v = {3, 2, 4 ,5};

/*
1st choice - Initializer list
2nd choice - Regular constructor that takes those parameters
3rd choice - Aggregate initializer ( dog d1 = {5, "Henry"}; )

*/



//1st choice - Initializer list
class boVector{
	vector<int> m_vec;
public:
	boVector(const initializer_list<int> &v){
		for(initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
		{
			m_vec.push_back(*itr);
		}
	}
};


class dog
{
public:
	int var1;
	string var2;
	//var1 = 9;	Initialized at every constructor

	dog() { var1 = 8; }

	dog(const initializer_list<int>& vec)		//1st choice
	{
		var1 = *(vec.begin());
	}

	//dog(int a) { dog(); doOtherStuff(a);} 1 constructor inside other is undefined behaviour. Use init() function. dog(){ init(); }

	//C++11
	//dog(int a): dog(){ doOtherStuff(a);}	//1st constructor is in the init-list of 2nd

};


//auto a = 9.6 <- Declared as double


/*
//Works on classes that have begin(), end(), read-only access
for(auto i : v) { 
	
}

for(auto& i : v) {
	++i;
}
*/

/*
void foo(int i)

void foo(char* pc)

foo(NULL) // which one ?

Use foo(nullptr) to use foo(char* pc)
*/


/*
enum class a{green,blue};
enum class b{small,big};

a a_ = a::green;
b b_ = b::small;

//Compiler failure. Strong typed
if(a==b) {
	
}
*/

/*

Compile time assert

static_assert(sizeof(int)==4, "size is not 4")
*/

/*
C++ 03
class dog {
	
	public:
		dog() {...}
		dog(int a) { dog(); doOtherThings(a);} //Will create 2 dogs, not 1
}

C++ 11
class dog {
	
	public:
		dog() {...}

		//1st constructor is in the init-list of 2nd
		dog(int a) : dog() { //Will create 1 dog, and do other things
			doOtherThings(a);
		} 
}



*/


int main(void)
{
	//C++03 allows this
	//dog d = {1,"hero"};		//Aggregate Initialization - 3rd choice
	//boVector v{1,2,3};

/*
	for(auto it =vec.begin(); it!=vec.end(); ++it)	//instead of iterator
		cout << *it << endl;

	for(auto i:v)				//readonly access
		cout << i << endl;

	for(auto& i:v)				//modifiable access
		cout << i << endl;
*/
	//C++ 11
	//foo(nullptr)

	return 0;
}

