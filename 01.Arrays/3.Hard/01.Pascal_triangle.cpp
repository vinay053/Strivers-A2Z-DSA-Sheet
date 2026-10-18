/**
 * Problem: Pascal's Triangle (Get Row)
 * 
 * QUESTION:
 * Given an integer rowIndex, return the rowIndex-th (0-indexed) row of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it.
 * 
 * Example:
 * Input: rowIndex = 3
 * Output: [1, 3, 3, 1]
 * 
 * APPROACH:
 * Use binomial coefficient formula: C(n, k) = C(n, k-1) * (n - k + 1) / k
 * Starting with coefficient = 1, compute each column in linear time.
 * 
 * TIME COMPLEXITY: O(rowIndex)
 * SPACE COMPLEXITY: O(1) (excluding output vector)
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
vector<int> getRow(int rowIndex)
{
    vector<int> row(rowIndex + 1, 1);
    long long coefficient = 1;

    for (int col = 1; col <= rowIndex; col++)
    {
        coefficient = coefficient * (rowIndex - col + 1) / col;
        row[col] = (int)coefficient;
    }

    return row;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int rowIndex;
    if (!(cin >> rowIndex)) return;
    vector<int> row = getRow(rowIndex);
    for (int i = 0; i < (int)row.size(); i++)
    {
        cout << row[i] << (i == (int)row.size() - 1 ? "" : " ");
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
