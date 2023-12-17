#include<iostream>
using namespace std;

int x = 100;

class WithStatic{
	static int x; // static initialization not allowed here. initialization after class
	static int y;
public:
	void print() {
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
};

int WithStatic::x = 1;
int WithStatic::y = x+1;

int main()
{
	WithStatic ws;
	ws.print();
}		
