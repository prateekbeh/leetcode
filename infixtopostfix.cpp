#include<iostream>
#include<stack>
using namespace std;

int precedence(char c){
	if(c == '/' || c == '*'){
		return 2;
	}else if(c == '+' || c == '-'){
		return 1;
	}
	return -1;
}
int main(){
	string res = "";
	string exp = "a+b*c+d";
	int n = exp.length();
	stack<int> st;	
	for(int i = 0 ; i < n ; i++){
		char c = exp[i];
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
			res += c;
		}
		else if( c == '('){
			st.push(c);
		}else if( c == ')'){
			while( st.top() != '('){
				res += st.top();
				st.pop();
			}
			st.pop(); // remove the '('
		}
		else{
			while(!st.empty() && precedence(c) <= precedence(st.top())){
				res += st.top();
				st.pop();
			}
			st.push(c);
		}
	}
	while(!st.empty()){
		res += st.top();
		st.pop();
	}
	cout << res << endl;
	return 0;
}
