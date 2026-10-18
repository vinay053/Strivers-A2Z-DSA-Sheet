/**
 * Problem: Rotate Array Left and Right by K Places
 * 
 * QUESTION:
 * Given an array of integers, rotating array by k elements.
 * 
 * Example:
 * Input:
 * N = 7, array[] = {1, 2, 3, 4, 5, 6, 7}, k = 2
 * Output (Right Rotate): 6 7 1 2 3 4 5
 * Output (Left Rotate): 3 4 5 6 7 1 2
 * 
 * APPROACH:
 * Right rotate:
 * 1. Reverse the first (n - k) elements.
 * 2. Reverse the remaining k elements.
 * 3. Reverse the entire array.
 * 
 * Left rotate:
 * 1. Reverse the first k elements.
 * 2. Reverse the remaining (n - k) elements.
 * 3. Reverse the entire array.
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
void rightRotate(vector<int> &arr, int n, int k)
{
    if (n == 0) return;
    k = k % n;
    reverse(arr.begin(), arr.begin() + (n - k));
    reverse(arr.begin() + (n - k), arr.end());
    reverse(arr.begin(), arr.end());
}

void leftRotate(vector<int> &arr, int n, int k)
{
    if (n == 0) return;
    k = k % n;
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
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
    
    // Demonstrating right rotation (can switch to leftRotate as needed)
    vector<int> arr_right = arr;
    rightRotate(arr_right, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr_right[i] << (i == n - 1 ? "" : " ");
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