#include<iostream>
#include<typeinfo>
using namespace std;
int main(){
	char c = 65;
	cout << c << endl;
	char d = 'A';
	//cout << (int) d << endl;
	//cout << typeid(c).name() << endl;
	char c1[] = "hell";
	c1[0] = 't';
	c1[1] = 'o';
	cout << c1 << endl;
	//cout << typeid(c1).name() << endl;
	//cout << typeid("hello").name() << endl;
	//cout << strlen("hello") << endl;
	return 0;
}
