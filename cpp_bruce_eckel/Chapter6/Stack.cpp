#include<iostream>
#include<fstream>
using namespace std;

class Stack{
	struct Link{
		void * data;
		Link* next;
		Link(void* dat, Link* nxt){
			data = dat;
			next = nxt;
		}
		~Link(){};
	}* head;
public:
	Stack(){
		head = nullptr;	
	}
	~Stack(){}
	void push(void* dat){
		head = new Link(dat, head);
	}
	void* peek(){
		if(head != nullptr){
			return head->data;
		}
	}
	void* pop(){
		if(head == 0) return 0;
		void * res = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return res;
	}
};

int main(){
	Stack textLines;
	ifstream in("Stack.cpp");
	string line;
	while(getline(in,line)){
		textLines.push(new string(line));
	}
	string* s;
	while((s = (string*)textLines.pop()) != 0){
		cout << *s << endl;
		delete s;
	}
	return 0;
}
