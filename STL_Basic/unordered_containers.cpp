
#include <iostream>
#include <vector>


using namespace std;

int main() {


/*
	Unordered Associative containers -> Element order may change over time

	unordered_map / multimap, unordered_set / multiset

	Implemented using hash table
		-> Array of linked lists or buckets
		-> LLs are called entries
		-> Fast and effective hash fn. -> O(1) search

*/

	/*
		unordered_set<string> s = {"red", "green", "blue"}; -> No duplicates

		unordered_set<string>::const_iterator iter = s.find("green"); //O(1)

		s.insert("yellow"); O(1)

		vector<string> vec = {"purple", "pink"};
		s.insert(vec.begin(), vec.end());

		//Hashtable specific APIs
		s.load_factor(); //(Total no. of elements) / (Total no. of buckets)
		s.bucket(x); //Which bucket 'x' is at
		s.bucket_count(); //Total no. of buckets
	*/

	/*
		unordered_multiset -> allows duplicated elements
		unordered_map      -> unordered set of pairs
		unordered_multimap      -> unordered set of pairs that allows duplicate keys
	*/

	/*
		Hash collision -> performance degrade
					   -> Many items inserted at a few buckets.
					   -> So search becomes O(n) for traversing over the L.L.
	*/

	/*
		Unordered containers properties

		i) Fastest search/insert at any place - O(1)		Associative container takes O(log n)	vector, deque take O(n)

		ii) Unordered set/multiset -> Element cannot be changed
		    Unordered map/multimap -> Element key cannot be changed

		    
	*/

	/*
		Associative array
		- using map / unordered_map

		unordered_map<char, string> day = {{'S', "Sunday"}, {'M', "Monday"}};

		day['M'] = "New day";

		Multimap, unordered_multimap -> Can't do [] operator since they don't have unique keys
	*/

 

	/*
		Container adaptors
		- Provide restricted interface

		1. stack - LIFO push() pop() top()
		2. queue - FIFO push() pop() front() back()
		3. priority queue - first item always highest priority
	*/

	/*
		Another way of categorizing containers

		i) Array based - vector, deque

		ii) Node based - list + associative containers + unordered containers

		Array based containers invalidates pointer:
			- Native ptrs, iterators, references

		vec = {1, 2, 3, 4}
		int * p = &vec[2] //Points to 3
		v.insert(v.begin(), 0)
		cout << *p << endl  // 2 or ?
	*/

}
