/**
 * Problem: Longest Subarray with Sum K (Containing Positives and Negatives)
 * 
 * QUESTION:
 * Given an array containing N integers and an integer K, find the length of the longest
 * subarray with the sum of the elements equal to K.
 * 
 * Example:
 * Input:
 * N = 6, K = 15, A[] = {10, 5, 2, 7, 1, 9}
 * Output: 4
 * Explanation: The subarray is {5, 2, 7, 1}.
 * 
 * APPROACH:
 * Prefix sum with Hash Map:
 * -> Store the earliest index where each prefix sum was seen.
 * -> At each index i, pref_sum += A[i].
 * -> If pref_sum == K, ans = max(ans, i + 1).
 * -> If (pref_sum - K) is in map, ans = max(ans, i - mp[pref_sum - K]).
 * -> Only insert pref_sum into map if not already present (to maximize subarray length).
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
int lenOfLongSubarr(const vector<int> &A, int N, int K)
{
    long long pref_sum = 0;
    int ans = 0;
    unordered_map<long long, int> mp;

    for (int i = 0; i < N; i++)
    {
        pref_sum += A[i];
        if (pref_sum == K)
            ans = max(ans, i + 1);
        if (mp.find(pref_sum - K) != mp.end())
            ans = max(ans, i - mp[pref_sum - K]);
        if (mp.find(pref_sum) == mp.end())
            mp[pref_sum] = i;
    }
    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << lenOfLongSubarr(a, n, k) << "\n";
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