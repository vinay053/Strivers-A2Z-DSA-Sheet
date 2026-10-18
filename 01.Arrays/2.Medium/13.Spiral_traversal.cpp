/**
 * Problem: Spiral Matrix Traversal
 * 
 * QUESTION:
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 * 
 * Example 1:
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * Example 2:
 * Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * APPROACH:
 * 1. Initialize four boundaries: top = 0, bottom = n - 1, left = 0, right = m - 1.
 * 2. While top <= bottom and left <= right:
 *    - Traverse top row from left to right, then top++.
 *    - Traverse right column from top to bottom, then right--.
 *    - If top <= bottom, traverse bottom row from right to left, then bottom--.
 *    - If left <= right, traverse left col from bottom to top, then left++.
 * 3. Return the collected elements.
 * 
 * TIME COMPLEXITY: O(N * M)
 * SPACE COMPLEXITY: O(1) (excluding output storage)
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
vector<int> spiralOrder(const vector<vector<int>> &matrix)
{
    vector<int> ans;
    if (matrix.empty() || matrix[0].empty()) return ans;

    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        // Traverse top row
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse right column
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        // Traverse bottom row
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse left column
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n, m;
    if (!(cin >> n >> m)) return;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = spiralOrder(matrix);
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
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
