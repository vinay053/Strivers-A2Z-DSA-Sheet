Q. Where is an array stored?
Ans. A fixed size of block stored at random location, if we know the address of first element of an array, we can predict all the elements location.

Q1.1.2 Second Largest element in a array

my approach:
1. Take 2 variables and store first element in each
2. traverse array and check if there is any num bigger than both
3. if yes than put y -into x and num into y
4. if a num is bigger than y but not x then put y=num
5. finally return y
Time Complexity: O(N)
is it optimal:YES

Q1.1.3 Check if array is sorted in ascending?
 my approach:
 1. Traverse through each element and check if a[i]<a[i+1]
 2. if not then return false
 3. if loop completes return true
 Time Complexity: O(N)
 is it optimal:YES

Q1.1.4 Remove duplicate in place from sorted array
My Approach:
1. Take a variable index starting with 0
2. Traverse each element in array a
3. if a[i]<a[i+1], then index++ and a[index]=a[i+1]
4. Return index+1
Time complexity: O(N)
is it Optimal:YES, its formally known as 2 point approach.

Q1.1.5 Left rotate array form 1 place

My Approach:
1. take the first elemnent and store it in a variable
2. run a loop starting from 2nd elemnt and pushing them in by one place
   by doing a[i-1]=a[i]
3. at the end of the loop put the stored elemnt in last place
Time Complexity: O(N)
is it Optimal:YES!!

Q1.1.6 Left rotate array from D place(s)

My Approach:
1. Store index=D%N
2. move arr[index] to 1 place and store index=index-1
3. repeat until you reach index=0
4. then put the 0th element to last place and repeat the loop till you reach index=D+1
Time Complexity:O(N)
Is it Optimal:NO X

Optimal Approach:
1. Reverse array from 0 to D-1
2. Reverse array from D to N-1
3. Reverse 0 to N-1
Time Complexity:O(N)
Is it Optimal YES!

Q1.1.7 Move zeros to the end while keeping relative postion of array same
Input=[0,1,0,4,5]
Output=[1,4,5,0,0]

My Approach:
1. We will solve this via 2 pointer approach
2. Start with i till the first 0 element
3. then start j and stop it at first non 0 element and swap it with ith index
4. move i to next 0 element and repeat step 3
5. retrun final array
Time complexityO(N)
Is it optimal: YES!!

Q1.1.8 Given two sorted arrays **nums1** and **nums2**, return an array that contains the **union** of these two arrays. The elements in the union must be in ascending order.

The union of two arrays is an array where all values are distinct and are present in either the first array, the second array, or both.

Example 1
**Input**: nums1 = [1, 2, 3, 4, 5], nums2 = [1, 2, 7]
**Output**: [1, 2, 3, 4, 5, 7]
**Explanation**:
The elements 1, 2 are common to both, 3, 4, 5 are from nums1 and 7 is from nums2

Example 2
**Input**: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
**Output**: [1, 3, 4, 5, 6, 7, 8, 9]
**Explanation**:
The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2