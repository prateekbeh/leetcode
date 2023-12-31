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

# Heaps 

make_heap -> Rearranges the elements in the range [first,last) in such a way that they form a heap.

pop_heap -> Pop element from heap range 
Rearranges the elements in the heap range [first,last) in such a way that the part considered a heap is shortened by one:
The element with the highest value is moved to (last-1).
So, to remove the element from the last use vector v.pop_back();

push_heap -> Given a heap in the range [first,last-1), 
this function extends the range considered a heap to [first,last) by placing the value in (last-1) into its corresponding location within it.


# Sliding Window

Repeated DNA sequence
: Check for repeated sequence in a string.
Use rabin karp method by using hashValue;
static_cast used to cast the values to a particular data type.

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

**560.** Subarray sum equals K.

**Sliding window expects incrementing sum so this problem cannot be solved using sliding window.**
Test case : -1 - 1 1 , k = 0; Sliding window will not be able to determine the sum to be 0 ever.

Use Hashmap
Maintain a prefixSum var and a map to see if the prefix sum has already been encountered.
if prefixSum - k is seen in the map that means the sum l exists between some i and j.
[ 0... i ... j]  
```
for(int i = 0 ; i < nums.size() ; i++){
	prefixSum += nums[i];
	
	if(freqMap.find(prefixSum - k) != freqMap.end()){
		ans += freqMap[prefixSum - k];
	}
	freqMap[prefixSum]+=1;
}
```

**209** Subarray with a sum >= target.
- Use while loop instead of if condition to increment / decrement wend.

**159**
- If used in this problem for incrementing wend. 
- Also lamda function used.
- 

**340**  Longest substring with atmost k distinct characters.
 - Used map to store the index of the elements.
 - Retrieve the smallest Index and remove that from the map
 - Another ways could be use arrays to maintain count of chracters.
 - Use variable to maintain distince characters.


 **424** Longest repeating character - Atmost k characters can be replaced
 - We can use array to store the count of every variable.
 - Get the maxCount for a character.
 - if the window size - maxCount > k then shift the left pointer.


# Two pointers

**15**
	```
		while(cond1 && cond2) != while(cond1) { if (cond 2) } // This could enter infinite loop. write a negative condition loop !cond2 inside if.
		while(cond1 && cond2) == while(cond1) { if (!cond 2) } //This will work.
	```

**259**

lower_bound = returns smallest element greater than target , if all elem are smaller than target returns last
			  												 if all elem are greater than target returns first



# Fast and Slow pointer

The pointers can be used to traverse the array or list in either direction, 
however, one moves faster than the other. Generally, the slow pointer moves forward by a factor of one,
and the fast pointer moves by a factor of two in each step.
However, **the speed can be adjusted according to the problem statement**

**141.** Linked List Cycle 
Move fast pointer only if fast exists.
**Make sure nullptr->next never happens.**
when fast == nullptr the loop should break


**142.** Linked List Cycle  
Floyd Tortoise Hare algorithm.
move hare to starting point and keep the tortoise where it was.
move hare and tortoise at same speed now.

 
**457**


# Tree DFS

**297** Serialize and Deserialize a binary tree






# Tree BFS

**102** Binary Tree Level Order 

# K-way merge
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




