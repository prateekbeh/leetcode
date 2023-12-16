#include "mem.h"
#include<iostream>
using namespace std;
class MyString{
	Mem* buf;
public:
	MyString();
	MyString(char* str);
	~MyString();
	void concat(char* str);
	void print();
};

MyString::MyString() { buf = nullptr;}
MyString::MyString(char* str){
	buf = new Mem(strlen(str) + 1);
	strcpy((char*)buf->pointer(),str);
}
void MyString::concat(char* str){
	if(!buf) buf = new Mem;
	strcat((char*)buf->pointer(buf->msize() + strlen(str) + 1), str);
}
void MyString::print(){
	if(!buf) return;
	cout << buf->pointer()<<endl;
}
MyString::~MyString(){ delete buf;}

int main(){
	MyString s("My Test String");
	s.print();
}

