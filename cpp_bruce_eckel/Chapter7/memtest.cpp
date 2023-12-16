#include<iostream>
#include "mem.h"
using namespace std;

Mem::Mem(){
	mem = nullptr;
	size = 0;
}	
Mem::Mem(int sz){
	mem = nullptr;
	size = 0;
	ensureMinSize(sz);
}
Mem::~Mem(){
	delete []mem;
}
int Mem::msize(){
	return size;
}
void Mem::ensureMinSize(int minsz){
	if(size < minsz){
		byte* newmem = new byte[minsz];
		memset(newmem + size, 0 , minsz-size);
		memcpy(newmem, mem, minsz);
		delete []mem;
		mem = newmem;
		size = minsz;
	}
}
byte* Mem::pointer{return mem;}
byte* Mem::pointer(int minSize){
	ensureMinSize(minSize);
	return mem;
}
