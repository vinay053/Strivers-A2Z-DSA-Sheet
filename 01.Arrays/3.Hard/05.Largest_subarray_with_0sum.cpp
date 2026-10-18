/**
 * Problem: Largest Subarray with 0 Sum
 * 
 * QUESTION:
 * Given an array with both positive and negative integers, compute the length of the largest subarray with a sum of 0.
 * 
 * Example:
 * Input:
 * N = 8, A[] = {15, -2, 2, -8, 1, 7, 10, 23}
 * Output: 5
 * Explanation: The largest subarray with a sum of 0 is {-2, 2, -8, 1, 7}.
 * 
 * APPROACH:
 * Prefix sum with hash map:
 * -> Store the earliest index where each prefix sum was seen.
 * -> Initialize mp[0] = -1.
 * -> For each index, pref_sum += A[i].
 * -> If pref_sum is already seen at index j, length = i - j. ans = max(ans, length).
 * -> Otherwise, record mp[pref_sum] = i.
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
int maxLen(const vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    mp[0] = -1;
    int pref_sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        pref_sum += A[i];
        if (mp.find(pref_sum) != mp.end())
        {
            ans = max(ans, i - mp[pref_sum]);
        }
        else
        {
            mp[pref_sum] = i;
        }
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxLen(a, n) << "\n";
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
