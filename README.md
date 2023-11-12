# leetcode
Leetcode problem and daily Notes

## Reference articles


Backtracking Patterns: https://lnkd.in/g9csxVa4

Sliding Window patterns: https://lnkd.in/gjatQ5pK

Sliding Windows on Strings Pattern: https://lnkd.in/gX8ebtnb

Two Pointers Patterns: https://lnkd.in/gBfWgHYe

Substring Problem Patterns: https://lnkd.in/gdGtE72g

Tree Patterns: https://lnkd.in/gKja_D5H

Tree Iterative Traversal: https://lnkd.in/gGpXjHt5

Dynamic Programming Patterns: https://lnkd.in/gbpRU46g

Binary Search Patterns: https://lnkd.in/gKEm_qUK

Monotonic Stack Patterns: https://lnkd.in/gdYahWVN

Bit Manipulation Patterns: https://lnkd.in/gkxVZTXU

Graph Patterns: https://lnkd.in/gKE6w7Jb

DFS + BFS Patterns (1): https://lnkd.in/gPgpsgaQ

DFS + BFS Patterns (2): https://lnkd.in/gd4ekfQe

14 Coding Interview Patterns: https://lnkd.in/gMZJVkFf


## Useful Code snippets

### For comparator function check from bottom to top in case of a Priority queue (in case of tree)

```
	bool operator()(PII below, PII above)
    {
        if (below.first > above.first) {  // min heap property
            return true;  
        }
        else if (below.first == above.first
                 && below.second < above.second) {   // max heap property
            return true;
        }
 
        return false;
    }

	Output: 
	1 20
	1 2
	1 1
	100 41
	100 21
	100 11
	300 2
	300 1

```
if you consider array representation then the higher values will be at right and lower at the left

### Heaps 

make_heap -> Rearranges the elements in the range [first,last) in such a way that they form a heap.

pop_heap -> Pop element from heap range 
Rearranges the elements in the heap range [first,last) in such a way that the part considered a heap is shortened by one:
The element with the highest value is moved to (last-1).
So, to remove the element from the last use vector v.pop_back();

push_heap -> Given a heap in the range [first,last-1), 
this function extends the range considered a heap to [first,last) by placing the value in (last-1) into its corresponding location within it.


## Sliding Window

Repeated DNA sequence
Check for repeated sequence in a string.
Use rabin karp method by using hashValue;
For every substring of length k do the following:
```
		if( i == 0 ){
			for(int j = 0 ; j < k ; j++){
				hashValue += nums[j] * static_cast<int> (pow(a,k-j-1));
			}
		}
		else{
			int prevHash = hashValue;
			hashValue = ((prevHash - nums[i - 1] * static_cast<int>(pow(a, k - 1))) * a) + nums[i + k - 1];
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




