
/*
												Implicit	Explicit
	Standard type conversion - built-in type	  A            B
	User defined conversion - classes             C            D
                                                           (casting)

*/
/*
	A type
	char c = 'A';
	int i = c ;		//Integral promotion

	char* pc = 0 	//Int-> null pointer

	void f(int i)
	f(c);
	dog* pd = new YellowDog();	//pointer. type conversion
*/


#include <iostream>
#include <vector>

using namespace std;

//Constructor - Other types to your object
//Type conversion fn. - Your object to other types

class dog
{
public:
	dog(){}
	dog(string name) { //NO explicit. If implicit needs to be avoided use 'explicit' keyword
		cout << " string constructor called "<< endl;
		name_ = name;
	}

	string getName(){return name_;}
	operator string() const {return name_;}			// Implicit Type conversion fn from dog to string

private:
	string name_;
};

/*
GUIDELINES:
1) Avoid seeming unexpected conversion
2) 
*/

class Rational
{
public:
	Rational(int numer = 0, int denom = 1):num(numer), den(denom){ cout << " first constructor " << num << " " << den << endl; }

	const Rational operator*(const Rational&rhs){		// (TWO)
		return Rational(num*rhs.num, den*rhs.den);
	}

	// operator int() const{ return num/den;}	//THREE     Type Conversion fn.

	int num, den;
};
//We can't use both TWO  and THREE as it is 2 way implicit conversion
//Use this non-member variable fn. instead of the 2 member functions
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
	return Rational( lhs.num*rhs.num, lhs.den*rhs.den);
}



int main(void)
{
	string dogname = "D1";
	dog Dog1;
	cout << " before assignment " << endl;
	Dog1 =  dogname ;

	string d2 = Dog1;
	cout << d2 << endl;
	//printf("%s\n", Dog1);

	Rational r1 = 23;
	Rational r2 = r1*2;		//Will compile only if TWO used(2->R) but not if THREE is there r1 to int is also possible leading to ambiguity
	Rational r3 = 2*r1;		//Will compile only if THREE used(R->Integer)

	return 0;
}

