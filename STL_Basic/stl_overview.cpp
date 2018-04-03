
#include <iostream>
#include <vector>


using namespace std;


//N Algos + M containers = N*M implementations
//Iterators -> N + M implementations

/*
Sequence Containers (array and linked list)

vector - dynamic array
deque, list, forward list, array

Associative Containers (binary tree) - sorted

set, multiset
map, multimap

Unordered Containers (hash table)

Unordered set/multiset
Unordered map/multimap

*/


int main() {

	vector<int> vec; //Dynamic array growing at the end (back)
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	/*
	cout << vec[2]; <--- No range check
	vec.at(2);      <--- Throws range_error
	*/

	int* p = &v[0];
	p[2] = 6;


	/*
	Common members for all containers
	vec.empty();

	vec.size();

	vec(vec2) //Copy constructor

	vec.clear(); //Remove all items

	vec2.swap(vec);
	*/

	/*
	Fast insert/remove at the end
	Slow insert/remove in middle O(n)
	Slow search O(n)

	*/

	/*
	deque<int> deq = {4,6,7}; //Grows both side, Contiguous

	deq.push_front(3);
	deq.push_back(8);
	//3, 4, 6, 7

	Fast insert/remove at beginning and end
	Slow insert/remove in middle O(n)
	Slow search O(n)
	*/


	/*
		list<int> mylist = {5, 2, 9};
		mylist.push_front(3);
		mylist.push_back(11);
		//3, 5, 2, 9, 11

		list<int>::iterator iter = find(mylist.begin(), mylist.end(), 2);
		mylist.insert(iter, 8); //Inserted before 2

		//3, 5, 8, 2, 9, 11


		Fast insert/remove O(1)
		Slow search O(n)
		- Slower than vector due to cache misses, has additional memory due to ptrs.

		No random access, []

		myList.splice(itr, mylist2, itr_a, itr_b);
		//Constant time. LIST SPECIALITY None of the other containers have this
	*/

	/*
		Forward list
	*/

	/*
		Array
		int a[3] = {3, 4, 5};

		array<int, 3> a = {3, 4, 5}; //Size remains const. once instantiated
		//Call all stl member fns.
		a.begin()
		a.size()
		a.swap()
	*/

}
