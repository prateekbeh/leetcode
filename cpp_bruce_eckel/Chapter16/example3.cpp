#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class Stack{
	struct Link{
		T* data;
		Link* next;
		Link(T* dat, Link* nxt): data(dat), next(nxt) { }
	}* head;
public:
	Stack() : head(0) {}
	~Stack(){
		while(head)
			delete pop();
	}
	void push(T* dat){
		head = new Link(dat,head);
	}
	T* peek() const{
		return head ? head->data:0;
	}
	T* pop(){
		if(head == 0) return 0;
		T* res = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return res;
	}
};

int main(){
	Stack<string> textLines;
	string line;
	ifstream in("example2.cpp");
	while(getline(in, line)){
		textLines.push(new string(line));
	}
	string* s;
	for(int i = 0 ; i < 10 ; i++){
		if((s = (string*)textLines.pop()) != 0){
			cout << *s << endl;
			delete s;
		}
	}
}
