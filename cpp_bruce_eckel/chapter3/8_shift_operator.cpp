#include<iostream>
using namespace std;

#define cerr(str) cout << str << endl;


void printBinary(const unsigned char val){
	/* These all statements are valid

		cout << (val + 2048) <<endl;
		cout << (char) (val + 256 + 256)<< endl;
		char f = (val + 256 + 256);
		cout << f << endl;
	*/
		
	for(int i = 7 ; i >= 0 ; i--){
		if(val & (1 << i)) cout << 1;
		else cout << 0;
	}
	cout << endl;

}

unsigned char rol(unsigned char val){
	int highbit;
	if(val & 0x80) highbit = 1;
	else highbit = 0;
	val <<= 1;
	val |= highbit;
	printBinary(val);
	cout << (int) val << endl;
	return val;
}

int main(){
		
	int c = 7;
	cout  << "After rotation :" << (c >> 32) << endl;
	cout << rol(c);
	return 0;
}
