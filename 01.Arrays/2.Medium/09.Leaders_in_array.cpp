/**
 * Problem: Leaders in an Array
 * 
 * QUESTION:
 * Given an array A of positive integers. Your task is to find the leaders in the array.
 * An element of array is leader if it is greater than or equal to all the elements to its right side.
 * The rightmost element is always a leader.
 * 
 * Example:
 * Input:
 * n = 6, A[] = {16, 17, 4, 3, 5, 2}
 * Output: 17 5 2
 * Explanation: The first leader is 17 as it is greater than all elements to its right.
 * Similarly, 5 and 2 are also leaders.
 * 
 * APPROACH:
 * -> Traverse the array from right to left.
 * -> Keep track of the maximum element seen so far (`maxi`).
 * -> If current element >= maxi, it's a leader. Add to result and update maxi.
 * -> Reverse the result to maintain original relative order.
 * 
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(N) (for output)
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
vector<int> leaders(const vector<int> &a, int n)
{
    vector<int> ans;
    if (n == 0) return ans;
    ans.push_back(a[n - 1]);
    int maxi = a[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] >= maxi)
        {
            ans.push_back(a[i]);
            maxi = a[i];
        }
    }

    reverse(ans.begin(), ans.end());
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
    vector<int> res = leaders(a, n);
    for (int i = 0; i < (int)res.size(); i++)
    {
        cout << res[i] << (i == (int)res.size() - 1 ? "" : " ");
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
