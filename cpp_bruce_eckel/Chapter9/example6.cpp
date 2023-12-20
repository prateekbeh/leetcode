// singleton pattern

#include<iostream>
using namespace std;

class Egg{
	static Egg e;
	int i;
	Egg(int ii) : i(ii){}   // constructor in Private to avoid access.
	Egg(const Egg&);  // Prevent copy construction 
public:
	static Egg* instance() { return &e; }
	int val() const { return i; }
};

Egg Egg :: e(47);

int main(){
	// Egg x(1); Error -- can't create an Egg.
	cout << Egg::instance()->val() << endl;
	return 0;
}
