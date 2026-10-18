/**
 * Problem: Maximum Subarray Sum (Kadane's Algorithm)
 * 
 * QUESTION:
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 * 
 * Example:
 * Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 * Output: 6
 * Explanation: The subarray [4, -1, 2, 1] has the largest sum 6.
 * 
 * APPROACH:
 * Kadane's Algorithm:
 * -> Iterate through the array maintaining curr_sum and ans (max sum).
 * -> curr_sum += nums[i].
 * -> ans = max(ans, curr_sum).
 * -> If curr_sum < 0, reset curr_sum = 0.
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
int maxSubArray(const vector<int> &nums)
{
    int curr_sum = 0;
    int ans = INT_MIN;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        curr_sum += nums[i];
        ans = max(ans, curr_sum);
        if (curr_sum < 0)
            curr_sum = 0;
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
    cout << maxSubArray(nums) << "\n";
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