#include<iostream>
using namespace std;

class Tree{
	int height;
public:
	Tree(int treeHeight) : height(treeHeight){ }
	~Tree() { cout << "*"; }
	friend ostream& operator<<(ostream& os , const Tree* t){
		return os << "Tree height is: " << t->height << endl;
	}
	
};

int main(){
	Tree* t = new Tree(40);
	cout << t;
	delete t;
}
