/**
 * Problem: Max Consecutive Ones
 * 
 * QUESTION:
 * Given a binary array nums, return the maximum number of consecutive 1's in the array.
 * 
 * Example:
 * Input: nums = [1, 1, 0, 1, 1, 1]
 * Output: 3
 * Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
 * 
 * APPROACH:
 * -> Traverse the array, maintain a counter `cnt` for consecutive 1's.
 * -> Whenever nums[i] == 1, increment cnt and update max.
 * -> When nums[i] == 0, reset cnt = 0.
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
int findMaxConsecutiveOnes(const vector<int> &nums)
{
    int ans = 0;
    int cnt = 0;
    for (int x : nums)
    {
        if (x == 1)
        {
            cnt++;
            ans = max(ans, cnt);
        }
        else
        {
            cnt = 0;
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
    cout << findMaxConsecutiveOnes(nums) << "\n";
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
