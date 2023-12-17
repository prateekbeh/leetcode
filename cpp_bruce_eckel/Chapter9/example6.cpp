// singleton pattern

#include<iostream>
using namespace std;

class Egg{
	static Egg e;
	int i;
	Egg(int ii) : i(ii){}
	Egg(const Egg&);  
	
