# leetcode
Leetcode problem and daily Notes

## Test

```
#include<bits/stdc++.h>
using namespace std;
int main(){
	
	return 0;
}
```

## K-way merge
used to merge K sorted data structures.
The basic idea behind the K-way merge algorithm is to repeatedly select the smallest (or largest, depending on the sorting order)
element among the K input lists and add it to the output list

### Algorithm1
	
Using a min heap

Insert the first element of each list in a min-heap.

Next, remove the smallest element from the heap and add it to the output list.

Keep track of which list each element comes from.

From the list from which the last element was selected, pick the next element and push it onto the heap.

Repeat steps 2 to 4 to fill the output list in sorted order.

### Algorithm2 
Making groups of 2 and repeatedly merging them

1. Begin by pairing up the k sorted lists into groups of 2

2. Merge each pair of lists using a standard two-way merge operation (like the one used in merge sort), resulting in k/2 merged lists.

3. If there are an odd number of lists in a group, leave one unmerged.

4. Repeat the process of pairing up and merging until only one sorted list remains, which is the final result.	

### Problem statements

The problem involves a set of sorted arrays, or a matrix of sorted rows or sorted columns that need to be merged, either for the final solution, or as an intermediate step.
The problem asks us to find the kth smallest or largest element in a set of sorted arrays or linked lists.
