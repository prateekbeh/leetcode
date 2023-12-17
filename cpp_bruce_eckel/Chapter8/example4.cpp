#include<iostream>
using namespace std;

class X{};

X f() { return X(); }

void g(X& ) {} // returns a non-const reference
void g2(const X& ) {}  // pass by const reference.

int main(){
	//g(f());  // not ok Error : const temporary created by f();
	g2(f()); // ok  takes a const reference;
	return 0;
}	
