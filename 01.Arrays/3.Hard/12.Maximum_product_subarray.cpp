/**
 * Problem: Maximum Product Subarray
 * 
 * QUESTION:
 * Given an integer array nums, find a subarray that has the largest product, and return the product.
 * 
 * Example:
 * Input: nums = [2, 3, -2, 4]
 * Output: 6
 * Explanation: [2, 3] has the largest product 6.
 * 
 * APPROACH:
 * Prefix and Suffix Product Traversal:
 * -> Iterate left-to-right maintaining cumulative product; reset to 1 upon seeing 0.
 * -> Iterate right-to-left doing the same (handles odd number of negative elements).
 * -> Global max of both passes is the answer.
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
int maxProduct(const vector<int> &nums)
{
    int ans = INT_MIN;
    long long prdct = 1;

    // Iterate from left to right
    for (int i = 0; i < (int)nums.size(); i++)
    {
        prdct *= nums[i];
        ans = max(ans, (int)prdct);
        if (prdct == 0)
            prdct = 1;
    }

    prdct = 1;

    // Iterate from right to left
    for (int i = (int)nums.size() - 1; i >= 0; i--)
    {
        prdct *= nums[i];
        ans = max(ans, (int)prdct);
        if (prdct == 0)
            prdct = 1;
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
    cout << maxProduct(nums) << "\n";
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
