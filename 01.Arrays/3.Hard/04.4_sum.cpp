/**
 * Problem: 4Sum
 * 
 * QUESTION:
 * Given an array nums of n integers, return an array of all the unique quadruplets
 * [nums[a], nums[b], nums[c], nums[d]] such that they sum to target.
 * 
 * Example:
 * Input: nums = [1, 0, -1, 0, -2, 2], target = 0
 * Output: [[-2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]
 * 
 * APPROACH:
 * 1. Sort the input array nums.
 * 2. Fix first two elements using nested loops with pointers a and b.
 * 3. Use two pointers c and d to find remaining two elements summing to target - (nums[a] + nums[b]).
 * 4. Skip duplicates at all levels (a, b, c, d).
 * 
 * TIME COMPLEXITY: O(N^3)
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
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int a = 0; a < n; a++)
    {
        if (a > 0 && nums[a] == nums[a - 1]) continue;

        for (int b = a + 1; b < n; b++)
        {
            if (b > a + 1 && nums[b] == nums[b - 1]) continue;

            int c = b + 1;
            int d = n - 1;
            long long rem = (long long)target - nums[a] - nums[b];

            while (c < d)
            {
                long long sum = (long long)nums[c] + nums[d];
                if (sum == rem)
                {
                    ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                    c++;
                    d--;
                    while (c < d && nums[c] == nums[c - 1]) c++;
                    while (c < d && nums[d] == nums[d + 1]) d--;
                }
                else if (sum < rem)
                {
                    c++;
                }
                else
                {
                    d--;
                }
            }
        }
    }

    return ans;
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
    vector<vector<int>> res = fourSum(nums, target);
    cout << res.size() << "\n";
    for (const auto &quad : res)
    {
        cout << quad[0] << " " << quad[1] << " " << quad[2] << " " << quad[3] << "\n";
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
