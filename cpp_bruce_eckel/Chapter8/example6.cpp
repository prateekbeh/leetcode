#include<iostream>
using namespace std;

class Integer{
	const int i;
public:
	//Integer(int ii = 10) : i(ii) { }
	Integer(int ii = 10) : i(ii){
		// i = 100 Not ok Attempt to modify const variable inside constructor. Only possible inside constructor list
	}	
	void print() { cout << i << " " ; }
};

int main(){
	Integer i[100];
	for(int j = 0 ; j < 100 ; j++){
		i[j].print(); // print 100 10's
	}
}
