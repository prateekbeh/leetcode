#include<iostream>
using namespace std;

int main(){
	string bigNews("I saw elvis in a UFO");	
	cout << bigNews << endl;
	cout << "size = " << bigNews.size() << endl;
	bigNews.insert(0, " I thought " );
	cout << bigNews << endl;
	bigNews.append( " There is a stoem " );
	cout << bigNews << endl;
	string tag = "tag";
	bigNews.insert(10, tag + ' ');
	cout << bigNews << endl;
	int start = bigNews.find(tag);
	cout << "start = " << start << endl;
	bigNews.replace(start, tag.size() , "hello there");
	cout << bigNews << endl;
	return 0;
}
