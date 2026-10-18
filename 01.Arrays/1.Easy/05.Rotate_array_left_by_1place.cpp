/**
 * Problem: Rotate Array Left by One Place
 * 
 * QUESTION:
 * Given an array of N integers, left rotate the array by one position.
 * 
 * Example:
 * Input:
 * N = 5, array[] = {1, 2, 3, 4, 5}
 * Output: 2 3 4 5 1
 * Explanation:
 * We moved the 2nd element to 1st, 3rd to 2nd, 4th to 3rd, 5th to 4th, and 1st to 5th.
 * 
 * APPROACH:
 * -> Store arr[0] in a temp variable.
 * -> Traverse the array and shift arr[i] = arr[i+1].
 * -> Place temp at arr[n-1].
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
vector<int> rotateArray(vector<int> &arr, int n)
{
    if (n <= 1) return arr;
    int temp = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
    return arr;
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
    rotateArray(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << (i == n - 1 ? "" : " ");
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