#include<iostream>
using namespace std;

#define P(EX) cout << #EX << ": " << EX << endl;

void func1(int a[], int sz){
	for(int i = 0 ; i < sz; i++){
		a[i] = i*i-i;
	}
}
void func2(int * a, int sz){
	for(int i = 0 ; i < sz ; i++){
		a[i] = i*i+i;
	}
}
 
int main(){
	int a[10];
	int * ip = a;
	for(int i = 0 ; i < 10 ; i++){
		ip[i] = i*10;
	}
	//func1(a, 10);
	//func2(a,10);
	cout << a[5] << endl;
	P(*ip); // 0
	P(*++ip); // 10
	// before exexuting below statement ip is pointing to first element
	P(*(ip+5));	//60 
	int * ip2 = ip + 5;
	P(*ip2);
	P(*(ip2-4));
	P(*--ip2);
	P(ip2-ip);
	return 0;
}
