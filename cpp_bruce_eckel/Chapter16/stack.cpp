#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class StackTemplate{
	enum { ssize = 100 };
	T stack[ssize];
	int top;
public:
	StackTemplate() : top(0) { }
	void push(const T& i){
		stack[top++] = i;
	}
	T pop(){
		return stack[--top];
	}
	int size() { return top; }
};

int main(){
	StackTemplate<int> is;
	for(int i = 0 ; i < 20 ; i++){
		is.push(i);
	}
	for(int i = 0 ; i < 20 ; i++){
		cout << is.pop() << endl;
	}
	ifstream in("stack.cpp");
	string line;
	StackTemplate<string> strings;
	while(getline(in,line)){
		strings.push(line);
	}
	while(strings.size() > 0){
		cout << strings.pop() << endl;
	}
}
