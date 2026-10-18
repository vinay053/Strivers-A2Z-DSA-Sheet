/**
 * Problem: Rearrange Array Elements by Sign
 * 
 * QUESTION:
 * You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
 * You should rearrange the elements of nums such that:
 * 1. Every consecutive pair of integers have opposite signs.
 * 2. For all integers of the same sign, the order in which they were present in nums is preserved.
 * 3. The rearranged array begins with a positive integer.
 * 
 * Example:
 * Input: nums = [3, 1, -2, -5, 2, -4]
 * Output: [3, -2, 1, -5, 2, -4]
 * 
 * APPROACH:
 * -> Use two pointers: i = 0 (for positive elements at even indices) and j = 1 (for negative elements at odd indices).
 * -> Iterate through nums, if nums[k] >= 0 place at ans[i] and i += 2; else place at ans[j] and j += 2.
 * 
 * TIME COMPLEXITY: O(N)
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
vector<int> rearrangeArray(const vector<int> &nums)
{
    int i = 0; // for +ve integers (even indices)
    int j = 1; // for -ve integers (odd indices)
    vector<int> ans(nums.size());
    for (int k = 0; k < (int)nums.size(); k++)
    {
        if (nums[k] >= 0)
        {
            ans[i] = nums[k];
            i += 2;
        }
        else
        {
            ans[j] = nums[k];
            j += 2;
        }
    }
    return ans;
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
    vector<int> ans = rearrangeArray(nums);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i == n - 1 ? "" : " ");
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