#include<iostream>
using namespace std;

class Obj{
	char c;
public:
	Obj(char cc) : c(cc){
		cout << "object initialized for " << c << endl;
	}
	~Obj(){
		cout << "object destroyted for " << c << endl;
	}
};

Obj a('a');

void f(){
	static Obj b('b');
}
void g(){
	static Obj c('c');
}

int main()
{
	cout << "inside main" << endl;
	f();
	// g() not called
	cout << "leaving main " << endl;
	return 0;
}


/*
	object initialized for a
	inside main
	object initialized for b
	leaving main 
	object destroyted for b
	object destroyted for a

*/
