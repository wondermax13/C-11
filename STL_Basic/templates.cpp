#include <iostream>


using namespace std;

//Function template
template <typename T>
T square(T x) {

	return x*x;
}

//Class template
template <typename T>
class BoVector {

	T arr[100];
	int size;

	BoVector() : size(0) {

	}
		void push(T x) {}

};

int main() {

	//Code bloat since 2 different functions in memory
	cout << square(5) << endl;
	cout << square(5.5) << endl;

	//Specify explicitly
	BoVector<int> bo;
}
