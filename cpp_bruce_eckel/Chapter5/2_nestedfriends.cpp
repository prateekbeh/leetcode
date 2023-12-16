#include<iostream>
using namespace std;
const int sz = 10;

struct Holder{
private:
	int a[sz];
public:
	void initialize();
	// inner struct pointer can only access array a if it is declared as friend;
	struct Pointer;  // first declration is imp to declare the Pointer struct as friend
	friend Pointer;  // declared as friend here
	struct Pointer{ 
	private:
		Holder* h;
		int *p;
	public:
		void initialize(Holder* h);
		void next();
		void prev();
		void top();
		void end();
		int read();
		void set(int i);
	};
};

void Holder::initialize(){
	memset(a,0,sz*sizeof(int));
}
void Holder::Pointer::initialize(Holder* rv){
	h = rv;
	p = rv->a;
}

void Holder::Pointer::next(){
	if(p < &(h->a[sz-1])) p++;
}
void Holder::Pointer::prev(){
	if(p > &(h->a[0])) p--;
}
void Holder::Pointer::top(){
	p = &(h->a[0]);
}
void Holder::Pointer::end(){
	p = &(h->a[sz-1]);
}
int Holder::Pointer::read(){
	return *p;
}
void Holder::Pointer::set(int i){
	*p = i;
}
int main(){
	Holder h;
	Holder::Pointer hp, hp2;
	int i;
	
	h.initialize();
	hp.initialize(&h);
	hp2.initialize(&h);
	for(int i = 0 ; i < sz ; i++){
		hp.set(i);
		hp.next();
	}
	hp.top();
	hp2.end();
	for(int i = 0; i < sz ; i++){
		cout << "hp = " << hp.read() << ",hp2 = " << hp2.read() << endl;
		hp.next();
		hp2.prev();
	}
}		
