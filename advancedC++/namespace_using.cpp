
/*
using

1) Keyword - bring all namespace members into scope -> Only in global scope

2) Declaration
	i) Bring specific namespace member -> Only in global scope
		using std::cout
		cout <<
	ii) Bringing base class member to current class scope


Name Hiding

class B {
	
	public:
		void f(int a);
}

class D : public B {
	
	public:
		void f(); -> Shadows B's fn. So use using B::f
}

D d;
d.f(8); -> Doesn't compile


Anonymous namespace

g();

namespace {
	
	void g()
	void h() { //Similar to global variables, fns.

		g(); //Calls local not global g
	}
}

int main() {
	
	h();
}
*/
