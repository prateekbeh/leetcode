
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



