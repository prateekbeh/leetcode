#include<iostream>
#include<fstream>
using namespace std;

ofstream out("HowMany.out");

class HowMany{
	static int objectCount;
public:
	HowMany() { objectCount++; }
	static void print(const string& msg = ""){
		if(msg.size() != 0) out << msg << ": ";
		out << "objectCount= " << objectCount << endl;
	}
	~HowMany(){
		objectCount--;
		print("~HowMany()");
	}
};	

int HowMany::objectCount = 0;

HowMany f(HowMany x){
	// HowMany x -- called by value bitwise copy happens constructor not called.
	x.print("x argument inside f"); 
	return x;
	// destructor called for x so object Count -- 
}

int main()
{
	HowMany h; // constructor called
	HowMany::print("after construction of h");
	HowMany h2 = f(h);  // bitwise copy for h2 so not constructor called.
	HowMany::print("after call to f()");
	return 0;
	// after call to main the object h and h2 are desructed so ObjectCount -= 2;
}	


/*
	after construction of h: objectCount= 1
	x argument inside f: objectCount= 1
	~HowMany(): objectCount= 0
	after call to f(): objectCount= 0
	~HowMany(): objectCount= -1
	~HowMany(): objectCount= -2
*/
