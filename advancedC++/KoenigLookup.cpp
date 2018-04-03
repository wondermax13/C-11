
//Eg. 1
namespace A {
	
	struct X();
	void g(X) {cout << "" << endl;}
}

int main() {

	A::X x1;
	g(x1); //Compiles because compiler searches scope of parameter where defined .i.e. Koenig lookup
}

//Eg. 2
class C {
public:
	struct Y;
	static void h(Y) { cout << " " << }
};

int main() {

	C::Y y1;
	h(x1); //Doesn't compile because compiler only searches namespaces not classes
}


//Eg. 3
namespace A {
	
	struct X();
	void g(X) {cout << "" << endl;}
}

namespace C {
	
	void g(A::X) {cout << "" << endl;}

	void j() {

		A::X x;
		g(x);
	}
}

int main() {

	C::j(); //Won't compile since 2 g(x) collide

	//If C is class it will compile and call C.j().g()
}


//Eg. 4
namespace A {
	
	void g(X) {cout << "" << endl;}

	namespace C {

		void g();
		void j() {
			g(8);
		}
	}
}

int main() {

	A::C::j(); //Won't compile since g(x) and g() collide
			   //Soln. is inside C::j() use using A::g;
}

/*
1. 'using' keyword
2. Koenig lookup

*/

