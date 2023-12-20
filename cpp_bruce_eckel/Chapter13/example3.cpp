#include<iostream>
using namespace std;

class PStash {
	int quantity;
	int next;
	void ** storage;
	void inflate(int increase){
		const int pointersize = sizeof(void*);
		void ** st = new void* [increase + quantity];
		memset(st, 0, ((increase + quantity)* pointersize));  // memset sets memory bytewise
		memcpy(st,storage, quantity*pointersize);
		quantity += increase;
		delete[] storage;
		storage = st;
	}
public:
	PStash() : quantity(0), storage(0), next(0) {}
	~PStash() {
		delete []storage;
	}
	int add(void* elm){
		const int inflateSz = 10;
		if(next >= quantity){
			inflate(inflateSz);
		}
		storage[next++] = elm;
		return (next-1);
	}
	void* operator[](int index) const{
		if(index > next) return 0;
		return storage[index];
	}
	void* remove(int index){
		void* v = operator[](index);
		if( v!= 0) storage[index] = 0;
		return v;
	}
	int count() const { return next; }
};

int main(){
	PStash intStash;
	for(int i = 0 ; i < 25 ; i++){
		intStash.add(new int(i));
	}
	for(int j = 0 ; j < intStash.count() ; j++){
		cout << *(int*)intStash[j] << endl;
	}
	for(int k = 0 ; k < intStash.count() ; k++){
		delete intStash.remove(k);
	}
}
