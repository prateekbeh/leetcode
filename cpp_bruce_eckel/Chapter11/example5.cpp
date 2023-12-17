// Default copy constructor works on bitwise copy mechanism

#include<iostream>
using namespace std;

class WithCC{
public:
	WithCC() {}
	WithCC(const WithCC&) {
		cout << "WithCC(WithCC&)" <<endl;
	}
};

class WoCC{
	string id;
public:
	// Copy constructor is automatically called here that does bit wise copy.
	WoCC(const string& ident = "") : id(ident){}
	void print(const string& msg = "") const {
		if(msg.size() != 0) cout << msg << ": " << id << endl;
	}
};

class Composite{
	WithCC withcc;
	WoCC wocc;
public:
	// Copy constructor is also called here automatically which internally call copy constructor of WoCC and WithCC.
	Composite() : wocc("Composite()") { }
	void print(const string& msg = "") const {
		wocc.print(msg);  // calls the method for wocc object
	}
};

int main(){
	Composite c;
	c.print("Contents of c");
	cout << "Calling Composite copy-constructor" << endl;
	Composite c2 = c;
	c2.print("Contents of c2");
	return 0;
}
