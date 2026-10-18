/**
 * Problem: Remove Duplicates from Sorted Array
 * 
 * QUESTION:
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
 * each unique element appears only once. The relative order of the elements should be kept the same.
 * Then return the number of unique elements in nums.
 * 
 * Example:
 * Input: nums = [1, 1, 2]
 * Output: 2, nums = [1, 2, _]
 * 
 * APPROACH:
 * -> Keep a pointer k which signifies that up to k the array contains unique elements.
 * -> Traverse the entire array; if nums[k] != nums[j], increment k and swap nums[k] with nums[j].
 * -> Return k + 1.
 * 
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
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
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty()) return 0;
    int k = 0; // up to k, array contains unique elements
    for (int j = 1; j < (int)nums.size(); j++)
    {
        if (nums[k] != nums[j])
        {
            k++;
            swap(nums[k], nums[j]);
        }
    }
    return k + 1;
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
    int k = removeDuplicates(nums);
    cout << k << "\n";
    for (int i = 0; i < k; i++)
    {
        cout << nums[i] << (i == k - 1 ? "" : " ");
    }
    cout << "\n";
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