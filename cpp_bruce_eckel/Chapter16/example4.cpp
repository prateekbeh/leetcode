#include<iostream>
#include<fstream>
using namespace std;

template<class T, int incr = 100>
class PStash{
	int quantity;
	int next;
	T** storage;
	void inflate(int increase){
		const int psz = sizeof(T*);
		T** st = new T*[quantity + increase];
		memset(st, 0 , (quantity + increase) * psz);   // bytewise copy using memset
		memcpy(st, storage, quantity*psz);
		quantity += increase;
		delete []storage;
		storage = st;
	}
public:
	PStash() : quantity(0), next(0), storage(0) {}
	~PStash()
	 {
		for(int i = 0 ; i < next ; i++){
			delete storage[i];
			storage[i] = 0;
		}
		delete[] storage;
	}
	int add(T* element){
		if(next >= quantity){
			inflate(10);
		}
		storage[next++] = element;
		return (next-1);
	}
	T* operator[](int index) const{
		if(index >= next){
			return 0;
		}
		return storage[index];
	}
	T* remove(int index){
		T* v = operator[](index);
		if( v != 0 ) storage[index] = 0;
		return v;
	}
	int count() const { return next;}
};
int main(){
	ifstream in("example4.cpp");
	string line = "";
	PStash<string> stringStash;
	while(getline(in,line)){
		stringStash.add(new string(line));
	}
	for(int u = 0 ; stringStash[u] ; u++){
		cout << *stringStash[u] << endl;
	}
}
