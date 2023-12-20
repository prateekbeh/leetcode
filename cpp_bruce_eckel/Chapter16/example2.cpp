#include<iostream>
using namespace std;

template<class T, int sz = 100>  // sz defined at compile time
class Array{
	T array[sz];
public:
	T& operator[](int index){
		return array[index];
	}
	int length() const { return sz; }
};

class Number{
	float f;
public:
	Number(float ff = 0.0f) : f(ff) { }
	
	Number& operator=(int n){
		printf("Overloaded operator= called %d\n", n);
		f = n;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Number& x){
		return os << x.f;
	}
	operator float() const { return f; }
};

template<class T, int size = 20>
class Holder{
	Array<T,size>* np;
public:
	Holder() : np(0) {}
	T& operator[] (int i){
		if(!np) np = new Array<T,size>;
		return np->operator[](i);
	}
	int length() const { return size; }
	~Holder() { delete np; }
};

int main(){
	Holder<Number> h;
	for(int i = 0 ; i < 20 ; i++){
		printf("before operator= call \n");
		h[i] = i;
		printf("after operator= call \n");
	}
	for(int j = 0 ; j < 20 ; j++){
		cout << h[j] << endl;
	}
}
