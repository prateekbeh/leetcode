#include<iostream>
using namespace std;

class X{
	int i;
	static int j;
public:
	X(int ii = 0) : i(ii){
		// Non static member functions can access static meber functions.	
		j = i;
	}
	int val() const { return i;}
	static int incr(){
		// i++ -> static member function cannot acces non-static member function,
		return ++j;
	}
	static int f(){
		// val() static member finction cannot access nonstatic meber function.
		return incr();
	}
};
	
int X::j = 0;

int main()
{
	X x;
	X* xp = &x;
	x.f();
	xp->f();
	X::f();
	return 0;
}
