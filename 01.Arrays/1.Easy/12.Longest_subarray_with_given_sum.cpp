/**
 * Problem: Longest Subarray with Given Sum K (Positives)
 * 
 * QUESTION:
 * Given an array containing N integers and an integer K. Your task is to find the length
 * of the longest Sub-Array with the sum of the elements equal to the given value K.
 * 
 * Example:
 * Input:
 * N = 5, K = 10, A[] = {2, 3, 5, 1, 9}
 * Output: 3
 * Explanation: The subarray {2, 3, 5} has sum 10 and length 3.
 * 
 * APPROACH:
 * Two Pointer / Sliding Window (for non-negative elements):
 * -> Use two pointers start and end.
 * -> Keep expanding end and adding a[end] to sum.
 * -> While sum > k and start <= end, subtract a[start] and increment start.
 * -> If sum == k, update ans with max length (end - start + 1).
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
int longestSubarrayWithSumK(const vector<int> &a, long long k)
{
    int start = 0;
    int ans = 0;
    long long sum = 0;
    int n = a.size();

    for (int end = 0; end < n; end++)
    {
        sum += a[end];
        while (sum > k && start <= end)
        {
            sum -= a[start];
            start++;
        }
        if (sum == k)
        {
            ans = max(ans, end - start + 1);
        }
    }
    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << longestSubarrayWithSumK(a, k) << "\n";
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