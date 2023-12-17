#include<iostream>
#include<fstream>
using namespace std;

const int increment = 100;
class Stash{
	int size;
	int quantity;
	int next;
	unsigned char* storage;
	// inflate is made private as only other 
	// public member functions can access it.
	void inflate(int increase){
		int newQuantity = quantity + increase;
		int newBytes = newQuantity * size;
		int oldBytes = quantity * size;
		unsigned char* b = new unsigned char[newQuantity];
		for(int i = 0 ; i < oldBytes; i++){
			b[i] = storage[i];
		}
		delete [] storage;
		storage = b;
		quantity = newQuantity;
	}
public:
	Stash(int sz){
		size = sz;
		quantity = 0;
		next = 0;
		storage = nullptr;
	}
	~Stash(){
		if(storage != nullptr){
			cout <<" freeing storage" << endl;
			delete []storage;
		}
	}
	 
	int add(void* elm){
		if(next >= quantity){
			inflate(increment);
		}
		int startBytes = next * size;
		unsigned char* e = (unsigned char*) elm;
		for(int i = 0 ; i < size ; i++){
			storage[startBytes + i] = e[i];
		}
		next++;
		return (next - 1);
	}
	
	void* fetch(int index){
		if(index >= next){
			return 0;
		}
		return &(storage[index * size]);
	}
	
	int count(){
		return next;
	}
};

int main(){
	/*
	Stash intStash(sizeof(int));
	for(int i = 0 ; i < 100 ; i++){
		intStash.add(&i);
	}
	for(int j = 0 ; j < intStash.count() ; j++){
		cout << *(int*) intStash.fetch(j) << endl;
	}
	*/
	const int bufsize = 10;
	Stash stringStash(sizeof(char)*bufsize);
	ifstream in("Stash.cpp");
	string line;
	int mx = INT_MIN;
	while(getline(in,line)){
		stringStash.add((char*) line.c_str());
		mx = std::max(mx,(int)line.length());
	}
	cout << mx << endl;
	int k = 0;
	char* cp;
	while((cp = (char*)stringStash.fetch(k++)) != 0){
		string test = cp;
		cout << test.length() <<endl;
		cout << cp << endl;
	}
	return 0;
}
