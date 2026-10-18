/**
 * Problem: Linear Search
 * 
 * QUESTION:
 * Given an array arr[] of N integers and an integer K, check if K is present in the array or not.
 * Return the index if found, or -1 if not found.
 * 
 * Example:
 * Input:
 * N = 5, K = 7
 * arr[] = {1, 2, 3, 4, 7}
 * Output: 4
 * Explanation: 7 is present at index 4.
 * 
 * APPROACH:
 * Traverse the array using a loop. When an element equals K, return its index.
 * If the loop ends without finding K, return -1.
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
int linearSearch(const vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i;
    }
    return -1;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, k;
    if (!(cin >> n >> k)) return;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << linearSearch(arr, n, k) << "\n";
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