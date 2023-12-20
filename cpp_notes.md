
## Strings and Char arrays

Sequences of characters enclosed in double-quotes (") are literal constants.
And their type is, in fact, a null-terminated array of characters. 
This means that string literals always have a null character ('\0') automatically appended at the end.

Initializing an array of characters at the moment it is being declared, 
and not about assigning values to them later (once they have already been declared).
In fact, because string literals are regular arrays, they have the same restrictions as these, and cannot be assigned values.


However, individual assignments are possible
E.g:
	myword[0] = 'B';
	myword[1] = 'y';
	myword[2] = 'e';
	myword[3] = '\0';


In C++, even though the standard library defines a specific type for strings (class string),
still, plain arrays with null-terminated sequences of characters (C-strings) are a natural way 
of representing strings in the language; 
in fact, string literals still always produce null-terminated character sequences, and not string objects.

To convert string to char sequences we can use c_str();

## Data Types
```
	// These all will work. the value is get in  a single byte by truncation.

	char c = 65
	cout <<  c << endl;  // 'A'
	char d = 'A';
	cout << (int) d << endl; // 65 
	cout << (char) 65 + 256 + 256 << endl;  // 'A'
```

```
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    char ch = 65;
    cout << ch << endl;   // A
    cout << ch + 0 << endl;  // 65 . + converts to int.
     cout << char(ch + 32) << endl;   // a . explicit typecasting is required.
    return 0;
}
```

```
#include <bits/stdc++.h>
using namespace std;
 
// driver code
int main(){
    char value1 = 'a';
    char value2 = 'b';
    char value3 = 'z';
   
    // perform character arithmetic
    char num1 = value1 + 3;
    char num2 = value2 - 1;
    char num3 = value3 + 2;
   
    // print value
      cout<<"numerical value = "<<(int)num1<<endl;  // 100
      cout<<"numerical value = "<<(int)num2<<endl;  // 97 
      cout<<"numerical value = "<<(int)num3<<endl;  // 124

	  // upcasting/ typecasting
	  cout << value1 + 3 << endl;  // 100
  	  cout << value2 - 1 << endl;  // 97 
  	  cout << value3 + 2 << endl;  // 124  
	  
	  // num1, num2,num3 are of char type
	  cout<<"numerical value = "<<num1<<endl;  // d
      cout<<"numerical value = "<<num2<<endl;  // a 
      cout<<"numerical value = "<<snum3<<endl;  // |
    return 0;
}

```


char can only store values upto 128 , for unsigned char the value can be 0-255


## Operators

left shift, right shift operators -> shifts each bit to left or right specifiec by number of bits
shifting right greater than the width of data type can cause warning message shift count >= width of type

left shift and right shift can be used for right rotation and left rotation as well'

```
	unsigned char rotate_left(unsigned char val){
		int highbit;
		if(val & 0x80) highbit = 1;
		else highbit = 0;
		val <<= 1;
		val |= highbit;
		printBinary(val);
		cout << (int) val << endl;
		return val;
	}
```

## Constant

In C++, constants don't occupy storage. It's value is stored in the symbol table.
However, if the address of const or extern is defined for const the storage is allocated

### Default constructor is not created if we have defined a constructor explicitly

## Static objects
### static objects inside functions
	1. while initializing static objects of user defined types initialization is required for the object using constructor.
	2. static objects have internal linkage which means that it is local to the cpp file.
	3. The definition of staic data members must occur outside the class ( no inlining is allowed) . Only static const of integral types definition is allowed inside the class

## References and Copy Constructor

1. A reference must be initialized when created.
2. Once a reference is initialized to an object, it cannot be changed to refer to another object.
3. We cannot have NULL references.

	

### Argument passing guidelines
1. Always pass refernce to a function , if possible pass const reference. 
2. The only time poassing an address isn't preferable is when you're going to do such damage to object passing by value is the only option.


Copy constructor is only required when we want to pass an object of our class by value.


## Sample code snippets


```
	int n = s.length();
    const string c = s.substr(2,6);
    string res = "";
    
    bool afterNoon = s[n-2] == 'P' ? true : false;
    //cout << s[n-2] << endl;
    int hr = atoi(s.substr(0,2).c_str());
    hr = hr % 12;
    if(afterNoon)
        hr = hr + 12;
    if(hr < 10){
        res = '0' + to_string(hr) + c;	// char value added to string works.
    }else{
        res = to_string(hr) + c;
    }
    return res;

```

```
	string special_char = "!@#$%^&*()-+";
    int bit = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(password[i] >= '0' && password[i] <= '9'){
            bit |= (1 << 0);
        }else if(password[i] >= 'a' && password[i] <= 'z'){
            bit |= (1 << 1);
        }else if(password[i] >= 'A' && password[i] <= 'Z' ){
            bit |= (1 << 2);
        }else if(special_char.find(password[i]) != string::npos){    // string::npos is used to check for string exists or not.
            bit |= ( 1<< 3);
        }
    }
    int satisfied_cond = __builtin_popcount(bit);
    return max(6-n,4- satisfied_cond);

```


```
	string alphaL = "abcdefghijklmnopqrstuvwxyz";
    string alphaU = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = s.length();
    string res= "";
    for(int i = 0 ; i < n ; i++){
        auto pos = alphaL.find(s[i]);      // find returns size_t;
        auto pos1 = alphaU.find(s[i]);
        if(pos != string::npos){
            res += alphaL[(pos+k)%26];		// to rotate in array take n = len of array and not n - 1
        }
        else if(pos1 != string::npos){
            res += alphaU[(pos1+k)%26];
        }else{
            res += s[i];
        }
    }
    return res;
```

```
	long lo_counter = 3;
    long elapsed_time = 3;
    while(elapsed_time + lo_counter * 2 < t){
        elapsed_time += lo_counter * 2;
        lo_counter *= 2;
    }
    lo_counter *= 2;    // error is here base condition for 1 is not checked
    while(elapsed_time + 1 < t){
        lo_counter--;
        elapsed_time++;
    }
    return lo_counter;

```

```
	map<char, int> ms1;
    map<char,int> ms2;
    for(char c = 'a' ; c <= 'z' ; c++){			// initialization is important if I need to compare map values elem by elem
        ms1[c] = 0;
        ms2[c] = 0;
    }
    for(int i = 0 ; i < (int)s1.length() ; i++){
        ms1[s1[i]]++;
    }
    for(int i = 0 ; i < (int)s2.length() ; i++){
        ms2[s2[i]]++;
    }
    int ans = 0;
    cout << ms1.size() << " " << ms2.size() << endl;
    auto it1 = ms1.begin();
    auto it2 = ms2.begin();		// if iterator not used define the iterators outside the for loop;
    for(int i = 0 ; i < 26 ; i++){
        cout << it1->first << " == " << it1->second << it2->first << " ==  " << it2->second << endl;
        ans+= abs(it1->second - it2->second);
        it1++;it2++;
    }
    
    return ans;

```

```
	void insertionSort(int N, int arr[]) {
    int i,j;
    int value;
    for(i=1;i<N;i++)
    {
        value=arr[i];
        j=i-1;
        while(j>=0 && value<arr[j])
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=value;
    }
    for(j=0;j<N;j++)
    {
        printf("%d",arr[j]);
        printf(" ");
    }
}


```

```
	string isValid(string s) {
    int N = s.length();
    int num_char = 26;
    map<int,int> freq;
    for(int i = 0 ; i < N ; i++){
        freq[s[i] - 'a']++; 
    }
    vector<int> tmp;
    for(auto i : freq){
        tmp.push_back(i.second);
    }
    sort(tmp.begin() , tmp.end());
    
    int fi = tmp[0];
    int se = tmp[1];
    int second_last = tmp[tmp.size() - 2];
    int last = tmp[tmp.size() - 1];
    
    if(fi == last) return "YES";
    if(fi == 1 && se == last) return "YES";
    if(fi == second_last && last == second_last + 1) return "YES";
    return "NO";
}
```