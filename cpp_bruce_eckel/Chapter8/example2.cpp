#include<iostream>
using namespace std;

class X{
	int i;
public:
	X(int ii = 0){
		i = ii;
	}
	void modify(){
		cout << i << endl;
		//i++;
	}
};

X f5(){
	return X();
}

const X f6(){
	return X();
}

void f7(X& x){
	x.modify();
}

int main(){
	f5() = X(1);
	f5().modify();
	//f7(f5()); // compiler  as temporaries ( temporary object) returned from X5 is const and f7 takes reference
			  // so there can be an attempt to modify it.
	//f6() = X(1);
	//f6().modify();
	//f7((f6());
	return 0;
}	
