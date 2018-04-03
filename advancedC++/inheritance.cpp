
#include <iostream>

using namespace std;

class B
{
public:
	void f_pub() {cout << " f_pub " << endl;}
protected:
	void f_prot() {cout << " f_prot " << endl;}
private:
	void f_priv() {cout << " f_priv " << endl;}
};

/*
NOTES

1) No one can use B's private
2) D_pub keeps B's access for public, protected
3) D_priv keeps B's public, protected as private
4) D_prot keeps B's public, protected as protected
*/

// members, frnds., can cast * to B*
class D_priv:private B{

public:
	void f()
	{
		f_pub();	//private for D_pub
		f_prot();	//private for D_pub
		// f_priv();	//private can't be accesses
	}
};



// members, frnds., children can cast * to B*
class D_prot:protected B{

public:
	using B::f_pub; //Brings B's access(public) into D_prot
	void f()
	{
		f_pub();	//protected for D_pub
		f_prot();	//protected for D_pub
		// f_priv();	//private can't be accesses
	}
};

//anyone can cast * to B*
class D_pub:public B{
public:
	void f()
	{
		f_pub();	//public for D_pub
		f_prot();	//protected for D_pub
		// f_priv();	//private can't be accesses
	}
};	//anyone can cast * to B*

int main(void)
{
	D_pub Dpub;
	Dpub.f_pub();

	D_prot Dprot;
	Dprot.f_pub();
	
	B* pb = &D_pub;	//O.K.
	// pb = &Dprot; //Not O.K.

	return 0;
}

/*
//This is mostly used as it can have 2 rings
//If we want to override tinkle of ring() here we would need to create
another object inheriting from ring and making it a member of dog

COMPOSITION
class dog{
	ring r1;
	public:
		void tinkle(){ r1.tinkle(); }	//Call Forwarding
}

//This can be used only cases where we override virtual fn. in ring.
PRIVATE INHERITANCES
class dog:private ring{
	public:
		using ring::tinkle;

}

*/