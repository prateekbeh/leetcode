#include<iostream>
#include "2_Stack.h"
#include<fstream>
using namespace std;

void Stack :: Link :: initialize(void* dat, Link* nxt){
	data = dat;
	next = nxt;
}

void Stack::initialize(){
	head = nullptr;
}
void Stack::push(void* dat){
	Link * newLink = new Link;
	newLink->initialize(dat,head);
	head = newLink;
}
void* Stack::peek(){
	if(head == nullptr){
		cout << "Stack empty";
		exit(1);
	}
	return head->data;
}
void* Stack::pop(){
	if(head == 0) return 0;
	void* result = head->data;
	Link* oldHead = head;
	head = head->next;
	delete oldHead;
	return result;
}

int main(){
	ifstream in("../template.cpp");
	string line;
	Stack textLines;
	textLines.initialize();
	
	while(getline(in,line)){
		textLines.push(new string(line));  // --> new memeory allocated for every line.
		//textLines.push(&line); --> This will point to the same line .
	}	
	string* s;
	while((s = (string*)textLines.pop()) != nullptr){
		cout << *s << endl;
		delete s;
	}
	return 0;
}
