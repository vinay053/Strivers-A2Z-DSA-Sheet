/**
 * Problem: Subarray Sum Equals K
 * 
 * QUESTION:
 * Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 * 
 * Example:
 * Input: nums = [1, 1, 1], k = 2
 * Output: 2
 * 
 * APPROACH:
 * Prefix Sum with Hash Map:
 * -> Maintain a prefix sum and an unordered_map to store frequency of prefix sums.
 * -> At each element, pref_sum += nums[i].
 * -> If pref_sum == k, increment ans.
 * -> If (pref_sum - k) exists in the map, ans += mp[pref_sum - k].
 * -> Increment frequency of current pref_sum in the map.
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
int subarraySum(const vector<int> &nums, int k)
{
    int pref_sum = 0;
    unordered_map<int, int> mp;
    int ans = 0;

    for (int i = 0; i < (int)nums.size(); i++)
    {
        pref_sum += nums[i];

        if (pref_sum == k)
            ans++;

        if (mp.find(pref_sum - k) != mp.end())
        {
            ans += mp[pref_sum - k];
        }

        mp[pref_sum]++;
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << subarraySum(nums, k) << "\n";
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
