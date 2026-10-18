/**
 * Problem: Single Number (Find Element Present Only Once)
 * 
 * QUESTION:
 * Given a non-empty array of integers nums, every element appears twice except for one.
 * Find that single one.
 * 
 * Example:
 * Input: nums = [4, 1, 2, 1, 2]
 * Output: 4
 * 
 * APPROACH:
 * -> Use XOR operation: a ^ a = 0 and a ^ 0 = a.
 * -> Initial xr = 0, then traverse the array and xor each element with xr.
 * -> Duplicate elements cancel out, leaving the single element.
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
int singleNumber(const vector<int> &nums)
{
    int xr = 0;
    for (int x : nums)
    {
        xr ^= x;
    }
    return xr;
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
    cout << singleNumber(nums) << "\n";
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