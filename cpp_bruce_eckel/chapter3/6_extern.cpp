#include<iostream>
using namespace std;

extern int i;
void func();


int main(){
	i = 20;
	cout << i << endl;
	func();
}

void func(){
	i++;
	cout << i << endl;
}

