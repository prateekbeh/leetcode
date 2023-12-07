#include<iostream>
#include<fstream>
using namespace std;

typedef struct CStashTag{
	int size;
	int quantity;
	int next;
	unsigned char * storage;
} CStash;

int inc = 100;
void inflate(CStash*, int);

void initialize(CStash* s, int sz){
	s->size = sz;
	s->quantity = 0;
	s->next = 0;
	// assigning a int to a pointer . How?
	s->storage = 0;
}

int add(CStash* s, const void * elem){
	if(s->next >= s->quantity){
		inflate(s, inc);
	}
	int startBytes = s->next * s->size;
	unsigned char* e = (unsigned char*)elem;
	for(int i = 0 ; i < s->size ; i++){
		s->storage[startBytes + i] = e[i];
	}
	s->next++;
	return (s->next - 1);
}

void * fetch(CStash* s, int index){
	assert(0 <= index);
	if(index >= s->next){
		return 0;
	}
	return &(s->storage[index*s->size]);
}
int count(CStash* s){
	return s->next;
}
void inflate(CStash* s, int inc){
	assert(inc > 0);
	int newQuantity = s->quantity + inc;
	int newBytes = newQuantity * s->size;
	int oldBytes = s->quantity * s->size;
	unsigned char * b = new unsigned char[newBytes];
	for(int i = 0 ; i < oldBytes ; i++){
		b[i] = s->storage[i];
	}
	delete [](s->storage);
	s->storage = b;
	s->quantity = newQuantity;
}
void cleanup(CStash*s){
	if(s->storage != 0){
		delete [](s->storage);
	}
} 
int main(){
	CStash intStash, stringStash;
	int i;
	char * cp;
	ifstream in;
	string line;
	const int bufsize = 80;
	initialize(&intStash,sizeof(int));
	in.open("../template.cpp");
	for(int i = 0 ; i < 10 ; i++){
		add(&intStash, &i);
	}
	for(int i = 0 ; i < count(&intStash); i++){
		cout << *(int*)fetch(&intStash, i);
	}
	initialize(&stringStash, sizeof(char)*bufsize);
	while(getline(in, line)){
		add(&stringStash, line.c_str());
	}
	while((cp = (char*)fetch(&stringStash, i++))){
		cout << cp << endl;
	}
	cleanup(&intStash);
	cleanup(&stringStash);
}
