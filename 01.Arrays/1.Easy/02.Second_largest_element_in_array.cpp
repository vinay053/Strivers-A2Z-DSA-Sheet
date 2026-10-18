/**
 * Problem: Second Largest Element in Array
 * 
 * QUESTION:
 * Given an array Arr of size N, print second largest distinct element from an array.
 * 
 * Example:
 * Input:
 * N = 6
 * Arr[] = {12, 35, 1, 10, 34, 1}
 * Output: 34
 * Explanation: The largest element of the array is 35 and the second largest element is 34.
 * 
 * APPROACH:
 * -> If the current element is larger than 'large' then update second_large and large variables
 * -> Else if the current element is larger than 'second_large' and not equal to large, update second_large
 * -> Once we traverse the entire array, return second_large (-1 if no second largest exists).
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
int print2largest(const vector<int> &arr, int n)
{
    int prev = -1, curr = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > curr)
        {
            prev = curr;
            curr = arr[i];
        }
        else if (arr[i] > prev && arr[i] != curr)
        {
            prev = arr[i];
        }
    }
    return prev;
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
    cout << print2largest(arr, n) << "\n";
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