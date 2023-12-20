#include<iostream>
using namespace std;

class X{
	int i;
public:
	X(int ii = 0) : i(ii) { cout << " default constructor called" << endl; }  // this acts as both the constructor for X(int ) , X();
	~X() { cout << " Destructor called " << endl; }
};
void f(){
	static X x(47);
	static X x2;
}

int main(){
	f();
}
