
#include <iostream>
#include <vector>


using namespace std;

int main() {


/*
	Associative containers implemented using binary tree

	Associative -> Value associate with key

	Always sorted, default criteria is <

	No push_back(), push_front()

	set/multiset map/multimap
*/

	/*

		set<int> s; //No duplicates, sorted based on elements

		s.insert(3); //Insert always O(log n)
		s.insert(1);
		s.insert(7);

		//Always stay in sorted order -> {1, 3, 7}

		set<int>::iterator it = s.find(7);
		O(log n) Most imp. feature for associative container
		Seq. container don't even have a find method

		pair<set<int>::iterator, bool> ret; //bool indicates whether inserted. Otherwise duplicate exists
		ret = s.insert(3); //Will return false, iterator will point to old 3 entry
		it = ret.first

		s.insert(it, 9); //it provides hint -> {1, 3, 7, 9} - Can transform O(log n) -> O(n)

		s.erase(it) -> {1, 7, 9}

		s.erase(7) -> {1, 9} //O(log n) Seq. containers don't provide this
	*/

	/*
		multiset<int> m; //Can have duplicates

		set, multiset element values are non-modifiable
		*it = 10 //can't do - read only since tree is based on it

		Fast search - O(log n)
		Traversing is slow compared to vec/deq, since no locality
		No random access
	*/

	/*
		map - No duplicate keys,

		map<char, int> m;

		m.insert(make_pair('z', 200)); //Function template infers parameter types

		map<char, int>::iterator it = m.begin();

		m.insert(it, pair<char, int>('b', 300)); "it" is a hint

		it = m.find('z'); //O(log n)
	*/

	/*
		multimap - Can have duplicate keys

		multimap<char, int> m;

		map / multimap - keys can't be modified
						- type of *it -> pair<const char, int>
						(*it).first = 'd'; //Can't do

	*/

}
