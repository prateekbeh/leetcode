#include<iostream>
using namespace std;

int main()
{

	int n = 7;
	int spaces = 0;
	int stars = n;
	for(int row = 0 ; row < n ; row++){
		for(int star = 0 ; star < stars ; star++){
			cout << "*";
		}
		for(int space = 0 ; space < spaces ; space++){
			cout << " ";
		}
		for(int star = 0 ; star < stars ; star++){
			cout << "*";
		}
		stars -= 1;
		spaces += 2;
		cout << endl;
	}
	stars += 1;
	spaces -= 2;
	for(int i = 0 ; i < n; i++){
		for(int star = 0 ; star < stars ; star++){
			cout << "*";
		}
		for(int space = 0; space < spaces ; space++){
			cout << " ";
		}
		for(int star = 0 ; star < stars ; star++){
			cout << "*";
		}
		stars += 1;
		spaces -= 2;
		cout << endl;
	}
	return 0;
}
