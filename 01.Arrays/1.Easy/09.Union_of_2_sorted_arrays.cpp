/**
 * Problem: Union of Two Sorted Arrays
 * 
 * QUESTION:
 * Union of two arrays can be defined as the common and distinct elements in the two arrays.
 * Given two sorted arrays of size n and m respectively, find their union.
 * 
 * Example 1:
 * Input:
 * n = 5, arr1[] = {1, 2, 3, 4, 5}
 * m = 3, arr2[] = {1, 2, 3}
 * Output: 1 2 3 4 5
 * Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
 * 
 * Example 2:
 * Input:
 * n = 5, arr1[] = {2, 2, 3, 4, 5}
 * m = 5, arr2[] = {1, 1, 2, 3, 4}
 * Output: 1 2 3 4 5
 * 
 * APPROACH:
 * -> Take two pointers i and j where i is for arr1 and j is for arr2 and traverse.
 * -> If arr1[i] < arr2[j]: insert arr1[i] into union and advance while duplicate.
 * -> If arr2[j] < arr1[i]: insert arr2[j] into union and advance while duplicate.
 * -> If equal: insert once and advance both pointers past duplicates.
 * -> Traverse any remaining elements in either array.
 * 
 * TIME COMPLEXITY: O(N + M)
 * SPACE COMPLEXITY: O(N + M) (to return output)
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
vector<int> findUnion(const vector<int> &arr1, const vector<int> &arr2, int n, int m)
{
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            ans.push_back(arr1[i++]);
            while (i < n && arr1[i] == arr1[i - 1])
                i++;
        }
        else if (arr2[j] < arr1[i])
        {
            ans.push_back(arr2[j++]);
            while (j < m && arr2[j] == arr2[j - 1])
                j++;
        }
        else
        {
            ans.push_back(arr1[i++]);
            j++;
            while (i < n && arr1[i] == arr1[i - 1])
                i++;
            while (j < m && arr2[j] == arr2[j - 1])
                j++;
        }
    }

    while (i < n)
    {
        ans.push_back(arr1[i++]);
        while (i < n && arr1[i] == arr1[i - 1])
            i++;
    }
    while (j < m)
    {
        ans.push_back(arr2[j++]);
        while (j < m && arr2[j] == arr2[j - 1])
            j++;
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<int> arr1(n), arr2(m);
    for (int i = 0; i < n; i++) cin >> arr1[i];
    for (int i = 0; i < m; i++) cin >> arr2[i];

    vector<int> res = findUnion(arr1, arr2, n, m);
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