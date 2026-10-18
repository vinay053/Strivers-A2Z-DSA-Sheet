/**
 * Problem: Next Permutation
 * 
 * QUESTION:
 * A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
 * Given an array of integers nums, find the next lexicographically greater permutation of its integer elements.
 * If such an arrangement is not possible, it must be rearranged as the lowest possible order (i.e., sorted in ascending order).
 * 
 * Example 1:
 * Input: nums = [1, 2, 3]
 * Output: [1, 3, 2]
 * 
 * Example 2:
 * Input: nums = [3, 2, 1]
 * Output: [1, 2, 3]
 * 
 * APPROACH:
 * 1. Find the breakpoint bp from the right where nums[i] < nums[i+1].
 * 2. If no breakpoint exists (bp == -1), simply reverse the whole array.
 * 3. Otherwise, find the smallest element to the right of bp that is greater than nums[bp], and swap them.
 * 4. Reverse the suffix from bp + 1 to the end.
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
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int bp = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            bp = i;
            break;
        }
    }

    if (bp != -1)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[bp])
            {
                swap(nums[i], nums[bp]);
                break;
            }
        }
    }

    reverse(nums.begin() + bp + 1, nums.end());
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
    nextPermutation(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << (i == n - 1 ? "" : " ");
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
