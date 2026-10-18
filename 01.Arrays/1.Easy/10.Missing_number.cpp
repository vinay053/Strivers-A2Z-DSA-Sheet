/**
 * Problem: Missing Number
 * 
 * QUESTION:
 * Given an array nums containing n distinct numbers in the range [0, n], return the only number
 * in the range that is missing from the array.
 * 
 * Example:
 * Input: nums = [3, 0, 1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0, 3]. 2 is missing.
 * 
 * APPROACH:
 * -> Calculate expected sum of first n numbers: n * (n + 1) / 2
 * -> Calculate actual sum of elements in the array
 * -> Return expected sum - actual sum
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
int missingNumber(const vector<int> &nums)
{
    int n = nums.size();
    long long optimum_sum = ((long long)n * (n + 1)) / 2;
    long long actual_sum = 0;
    for (int x : nums)
    {
        actual_sum += x;
    }
    return (int)(optimum_sum - actual_sum);
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
    cout << missingNumber(nums) << "\n";
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