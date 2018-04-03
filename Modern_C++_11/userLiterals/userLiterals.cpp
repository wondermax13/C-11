
#include<iostream>

using namespace std;

/*
4 kinds of literals
integer - 45
floating point - 4.5
character - 'z'
string - "Dog"



45 - int literal
45u - unsigned int
45l - long

*/

//Constant expression used for compile time calculation
constexpr long double operator"" _mm(long double x){return x;}
constexpr long double operator"" _cm(long double x){return x*10;}
constexpr long double operator"" _m(long double x){return x*1000;}

//int operator"" _bin(const char* str, size_t l){Do something}

/*It can only be used with
char const*
unsigned long long
char const*, std::size_t
wchar_t const*, std::size_t
char16_t const*, std::size_t
char32_t const*, std::size_t
*/

int main(void)
{
	long double height = 3.4;  //metres, cms, inches ?
	int h = 3;
	cout << (height + 13.4_m) << endl; // = 3.4 + 13.4*1000
	return 0;
}
 