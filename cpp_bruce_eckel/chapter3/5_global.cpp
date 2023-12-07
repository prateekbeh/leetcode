#include<iostream>
using namespace std;

void func();
int global_val = 5;
int main(){
	
	global_val = 10;
	cout << global_val << endl;
	func();
	cout << global_val << endl;
	return 0;
}
