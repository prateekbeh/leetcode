#include<iostream>
using namespace std;
void f(int& ) {}
void g(const int& ) {}
int main()
{
	// f(1); -- Error : allocate storage to int, initialize it to 1 and produce address to bind to reference.
					// A temporary int is created in this case.
	g(1);
}
