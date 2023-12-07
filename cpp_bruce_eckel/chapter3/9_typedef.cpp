#include<iostream>
using namespace std;


// Both code will work. struct identifier can 
// be named after } also as in 2nd example
// struct Node is defined initialy to refer Node inside struct;
typedef struct Node{
	int data;
	Node * next;
	Node(){
		data = 5;
	}
} Node;


typedef struct{
	int data;
	//Node * next;
	//Node2(){
	//	data = 5;
	//}
} Node2;

int main(){
	Node2 * node = new Node2();
	cout << node << endl;
	//cout << *node << endl;
	cout << (*node).data << endl;
}
