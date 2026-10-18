/**
 * Problem: 3Sum
 * 
 * QUESTION:
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
 * i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * Input: nums = [-1, 0, 1, 2, -1, -4]
 * Output: [[-1, -1, 2], [-1, 0, 1]]
 * 
 * APPROACH:
 * 1. Sort the array.
 * 2. Iterate k from 0 to n - 1 (fix the first element).
 * 3. Use two pointers i = k + 1 and j = n - 1 to find pairs summing to -nums[k].
 * 4. Skip duplicates for k, i, and j.
 * 
 * TIME COMPLEXITY: O(N^2)
 * SPACE COMPLEXITY: O(1) (excluding output storage)
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
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int k = 0; k < n; k++)
    {
        if (k > 0 && nums[k] == nums[k - 1]) continue;

        int i = k + 1;
        int j = n - 1;
        int target = -nums[k];

        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                ans.push_back({nums[k], nums[i], nums[j]});
                i++;
                j--;
                while (i < j && nums[i] == nums[i - 1]) i++;
                while (i < j && nums[j] == nums[j + 1]) j--;
            }
            else if (sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
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
    vector<vector<int>> res = threeSum(nums);
    cout << res.size() << "\n";
    for (const auto &triplet : res)
    {
        cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << "\n";
    }
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
