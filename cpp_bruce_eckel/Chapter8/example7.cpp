#include<iostream>
using namespace std;

class StringStack{
	static const int size = 100;   // only static const variables can be defined in class directly
	// all other variables must be defined in contructor intializer list or memeber functions.

	const string* stack[size];
	int index;
public:
	StringStack() : index(0){
		memset(stack,0,sizeof(string*));
	}
	
	void push(const string* s){
		if(index < size){
			stack[index++] = s;
		}
	}
	const string* pop(){
		if(index > 0){
			const string* rv = stack[--index];
			stack[index] = 0;
			return rv;
		}
		return 0;
	}
		
};

string iceCream[] = {
		"pralines & cream",
		"fudge ripple",
		"jamocha almond fudge",
		"wild mountain berry"
	};
	

const int iCsz = sizeof iceCream / sizeof *iceCream;

int main(){
	StringStack ss;
	for(int i = 0 ; i < iCsz ; i++){
		ss.push(&iceCream[i]);
	}
	const string* cp;
	while((cp = ss.pop()) != 0){
		cout << *cp << endl;
	}
	return 0;
}
