/**
 * Problem: Largest Element in Array
 * 
 * QUESTION:
 * Given an array A[] of size n. The task is to find the largest element in it.
 * 
 * Example:
 * Input:
 * n = 5
 * A[] = {1, 8, 7, 56, 90}
 * Output: 90
 * Explanation: The largest element of given array is 90
 * 
 * APPROACH:
 * -> Initialize the ans with starting element
 * -> Traverse the entire array and update the ans if the element is greater than ans
 * -> Finally, return the ans
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
int largest(const vector<int> &arr, int n)
{
    int ans = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > ans)
            ans = arr[i];
    }
    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << largest(arr, n) << "\n";
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