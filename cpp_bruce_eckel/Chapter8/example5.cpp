#include<iostream>
using namespace std;
class Fred{
	const int size;
public:
	Fred(int sz) : size(sz){}
	void print() { cout << size << endl; }

};

int main(){
	Fred a(1), b(2), c(3);
	a.print(), b.print() , c.print();
}	
