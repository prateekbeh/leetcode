#include<iostream>
using namespace std;

void t(int* ){}

void u(const int* cip){
	// *cip = 2;  // Illegal -- modifies value
	int i = *cip;
	// int * ip2 = cip;  // Illegal non-const
}

const char* v(){
	return "result of function v()";
}

const int* const w(){
	static int i;
	return &i;
}
	
int main(){
	int x = 0;
	int * ip = &x;
	const int* cip = &x;
	t(ip);	// OK
	//t(cip); // Not ok
	u(ip); // ok
	u(cip); // ok
	// char* cp = v() // not ok -- return const char* but downgraded to char*
	const char* cp = v(); // ok
	// int* ip2 = w() // Not ok;
	const int* const ccip = w(); // ok -- 
	const int* cip2 = w(); //ok --;
	//*w() = 1; // not ok
	return 0;
}
