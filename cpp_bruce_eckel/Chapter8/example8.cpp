#include<iostream>
using namespace std;

class X{
	int i;
public:
	X(int ii) : i(ii) { }
	int f() const { return i;} // const member function has access to const object.
	// Other member functions cannot access the const object.
	// const member function can only call other const functions.
};

int main(){
	X x1(10);
	const X x2(20);
	x1.f();  // non const object + const function
	x2.f();  // const object + const function
}	
