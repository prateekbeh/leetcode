#include<iostream>
using namespace std;

void f(int& r){
	cout << r << " ";
	cout << &r << " ";
	r = 10;
	cout << r << endl;
}
int main(){
	int x = 5;
	cout << &x << endl;
	f(x);
	cout << "x=" << x << endl;
	return 0;
}
