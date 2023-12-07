#include<iostream>
using namespace std;

void f(){
	static int i = 0;
	cout << "i = " << ++i << endl;
}

int main(){
	for(int i = 0 ; i < 10 ; i++){
		f();
	}
	return 0;
}
