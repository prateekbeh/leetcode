#include<iostream>
using namespace std;

class Object{
	void * data;
	const int size;
	const int id;
public:
	Object(int sz , char c) : size(sz) , id(c) {
		data = new char[size];
		cout << "constructing object " << id << "size = " << size << endl;
	}
	~Object(){
		cout << "Destructing Object " << id << endl;
		delete[] data;
	}
};
int main(){
	Object* a = new Object(40, 'a');
	delete a;
	void* b = new Object(40, 'b');
	// delete b; frees the storage but does not call the destructor hence there is a memory leak;
	return 0;
}
