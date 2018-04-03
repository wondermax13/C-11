
#include <iostream>

using namespace std;


class File
{
public:
	string name;
	void open();
	File(string name){ cout << " File constructor " << endl;}
};

//Virtual base class. Tells it we want only 1 name and open() i.e. only 1 instance of File
class inputFile : virtual public File {
public:
	inputFile(string name) : File(name){cout << " inputFile constructor " << endl;}
};
/*public:
	void read();
	void open();
};*/

class outputFile: virtual public File{
public:
	outputFile(string name) : File(name){cout << " outputFile constructor " << endl;}
};
/*{
public:
	void open();
	void write();
};*/


class IOFile: public inputFile, public outputFile{	//Diamond shape hierarchy
public:
	// IMPORTANT
	// The initialization of the base virtual class is the responsibility of the most derived class
	IOFile(string name) : outputFile(name), inputFile(name), File(name){}
};

/*Interface segregation principle
Split large interfaces into smaller and more specific ones
so that clients only know about APIs that are of interest to them

class Andy{
	//500 APIs
};

//Engineer has 40 APIs, Son has 40 ....
//So segragate the 
class Andy : public Engineer, public Son ...{
	//500 APIs
};

*/

/*Pure Abstract Class
- Only pure virtual fns.
- No data members
- Avoids all problems like duplication of data, initialization, fn. implementation

class outputFile{
public:
	void virtual write()=0;
	void virtual open()=0;
};
*/


int main(void)
{
	IOFile f("NAME");
	f.open();	//Need to tell which open fn. to be used
	f.inputFile::name = "FILE1";
	f.outputFile::name = "FILE2";

	return 0;
}

