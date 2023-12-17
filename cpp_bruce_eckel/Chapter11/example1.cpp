// References in function

#include<iostream>
using namespace std;

int* f(int* x){
	(*x)++;
	return x;
}

int& g(int& x){
	x++;
	return x;
}

int& h(){
	int q;
	// return q;   Error q will be destroyed after function call ends so we cannot pass reference.
	static int x;
	return x; // ok
}
	
int main(){
	int a = 0;
	f(&a);
	g(a);
	return 0;
}
