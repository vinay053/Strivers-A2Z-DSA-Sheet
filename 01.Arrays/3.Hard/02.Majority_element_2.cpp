/**
 * Problem: Majority Element II (Appearing more than n / 3 times)
 * 
 * QUESTION:
 * Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
 * 
 * Example 1:
 * Input: nums = [3, 2, 3]
 * Output: [3]
 * 
 * Example 2:
 * Input: nums = [1]
 * Output: [1]
 * 
 * APPROACH:
 * Extended Boyer-Moore Voting Algorithm:
 * -> At most 2 elements can appear more than n/3 times.
 * -> Maintain candidates c1, c2 with vote counters vote1, vote2.
 * -> Second pass: count actual frequencies of c1 and c2.
 * -> Add those with count > n/3 to result.
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
vector<int> majorityElement(const vector<int> &nums)
{
    int n = nums.size();
    int c1 = 0, c2 = 0, vote1 = 0, vote2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == c1)
        {
            vote1++;
        }
        else if (nums[i] == c2)
        {
            vote2++;
        }
        else if (vote1 == 0)
        {
            c1 = nums[i];
            vote1 = 1;
        }
        else if (vote2 == 0)
        {
            c2 = nums[i];
            vote2 = 1;
        }
        else
        {
            vote1--;
            vote2--;
        }
    }

    int cnt1 = 0, cnt2 = 0;
    for (int x : nums)
    {
        if (x == c1) cnt1++;
        else if (x == c2) cnt2++;
    }

    vector<int> ans;
    if (cnt1 > n / 3) ans.push_back(c1);
    if (cnt2 > n / 3) ans.push_back(c2);
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
    vector<int> ans = majorityElement(nums);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
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
