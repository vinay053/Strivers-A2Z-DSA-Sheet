/**
 * Problem: Reverse Pairs
 * 
 * QUESTION:
 * Given an integer array nums, return the number of reverse pairs in the array.
 * A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
 * 
 * Example:
 * Input: nums = [1, 3, 2, 3, 1]
 * Output: 2
 * Explanation: Reverse pairs are (1, 4) [3 > 2*1] and (3, 4) [3 > 2*1].
 * 
 * APPROACH:
 * Merge Sort with Counting:
 * -> In merge step, before merging elements, use two pointers:
 *    for each element in left array, count how many elements in right array satisfy left[i] > 2 * right[m].
 * -> Then merge the two sorted halves normally.
 * 
 * TIME COMPLEXITY: O(N log N)
 * SPACE COMPLEXITY: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define all(x) (x).begin(), (x).end()

// ---------------------- SOLUTION ----------------------
int countPairs(vector<int> &nums, int start, int mid, int end)
{
    int right_start = mid + 1;
    int cnt = 0;
    for (int i = start; i <= mid; i++)
    {
        while (right_start <= end && (long long)nums[i] > 2LL * nums[right_start])
        {
            right_start++;
        }
        cnt += (right_start - (mid + 1));
    }
    return cnt;
}

void merge(vector<int> &nums, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (nums[i] <= nums[j])
        {
            temp.push_back(nums[i++]);
        }
        else
        {
            temp.push_back(nums[j++]);
        }
    }
    while (i <= mid) temp.push_back(nums[i++]);
    while (j <= end) temp.push_back(nums[j++]);

    for (int idx = start; idx <= end; idx++)
    {
        nums[idx] = temp[idx - start];
    }
}

int mergeSort(vector<int> &nums, int start, int end)
{
    int cnt = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        cnt += mergeSort(nums, start, mid);
        cnt += mergeSort(nums, mid + 1, end);
        cnt += countPairs(nums, start, mid, end);
        merge(nums, start, mid, end);
    }
    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, (int)nums.size() - 1);
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << reversePairs(nums) << "\n";
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
