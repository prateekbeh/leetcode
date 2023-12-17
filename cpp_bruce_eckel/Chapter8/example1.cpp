#include<iostream>
using namespace std;
int main(){
	//char * cp = "howdy" will not work as we try to change the const char * ;
	char cp[] = "howdy";
	cp[1] = 'i';
	cout << cp << endl;
	return 0;
}
