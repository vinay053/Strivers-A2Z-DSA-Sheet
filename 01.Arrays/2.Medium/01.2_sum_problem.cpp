/**
 * Problem: Two Sum
 * 
 * QUESTION:
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example 1:
 * Input: nums = [2, 7, 11, 15], target = 9
 * Output: [0, 1]
 * Explanation: nums[0] + nums[1] == 9, so return [0, 1].
 * 
 * APPROACH:
 * -> Use an unordered_map to store elements and their indices.
 * -> For each element, complement = target - nums[i].
 * -> If complement is already in the map, return {mp[complement], i}.
 * -> Otherwise, insert nums[i] into the map.
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
vector<int> twoSum(const vector<int> &nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < (int)nums.size(); i++)
    {
        int remain = target - nums[i];
        if (mp.find(remain) != mp.end())
            return {mp[remain], i};
        mp[nums[i]] = i;
    }
    return {-1, -1};
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, target;
    if (!(cin >> n >> target)) return;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> ans = twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << "\n";
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