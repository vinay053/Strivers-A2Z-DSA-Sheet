/**
 * Problem: Subarrays with XOR K
 * 
 * QUESTION:
 * Given an array 'A' consisting of 'N' integers and an integer 'B', find the number of subarrays
 * of array 'A' whose bitwise XOR of all elements is equal to 'B'.
 * 
 * Example:
 * Input: N = 4, B = 2, A = [1, 2, 3, 2]
 * Output: 3
 * Explanation: Subarrays with XOR 2 are: [1, 2, 3, 2], [2], [2].
 * 
 * APPROACH:
 * Prefix XOR with Hash Map:
 * -> Let pref_xr be the XOR sum up to the current index.
 * -> We want a previous prefix XOR `x` such that pref_xr ^ x = B, which means x = pref_xr ^ B.
 * -> Check how many times (pref_xr ^ B) has occurred previously in the map and add to ans.
 * -> If pref_xr == B, also increment ans.
 * -> Increment the frequency of pref_xr in the map.
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
int subarraysWithSumK(const vector<int> &a, int b)
{
    int pref_xr = 0;
    int ans = 0;
    unordered_map<int, int> mp;

    for (int i = 0; i < (int)a.size(); i++)
    {
        pref_xr ^= a[i];

        if (pref_xr == b)
            ans++;

        if (mp.find(pref_xr ^ b) != mp.end())
        {
            ans += mp[pref_xr ^ b];
        }

        mp[pref_xr]++;
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, b;
    if (!(cin >> n >> b)) return;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << subarraysWithSumK(a, b) << "\n";
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
