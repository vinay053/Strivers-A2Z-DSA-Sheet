/**
 * Problem: Longest Consecutive Sequence
 * 
 * QUESTION:
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 * 
 * Example:
 * Input: nums = [100, 4, 200, 1, 3, 2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
 * 
 * APPROACH:
 * -> Insert all elements into an unordered_set.
 * -> For each element, check if it is the start of a sequence (i.e. (num - 1) is not in the set).
 * -> If yes, count consecutively how many elements (num + 1, num + 2, ...) exist in the set.
 * -> ans = max(ans, streak length).
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
int longestConsecutive(const vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int ans = 0;

    for (int x : st)
    {
        // Only start counting if x is the beginning of a streak
        if (st.find(x - 1) == st.end())
        {
            int curr = x;
            int streak = 1;
            while (st.find(curr + 1) != st.end())
            {
                curr++;
                streak++;
            }
            ans = max(ans, streak);
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
    cout << longestConsecutive(nums) << "\n";
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
