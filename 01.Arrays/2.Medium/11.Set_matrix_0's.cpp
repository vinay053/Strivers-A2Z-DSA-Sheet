/**
 * Problem: Set Matrix Zeroes
 * 
 * QUESTION:
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it in place.
 * 
 * Example 1:
 * Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
 * Output: [[1,0,1],[0,0,0],[1,0,1]]
 * 
 * Example 2:
 * Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
 * Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 * 
 * APPROACH:
 * In-place using first row and first column as markers:
 * 1. Use two flags (firstRowZero, firstColZero) for the 0th row and column.
 * 2. Mark matrix[i][0] and matrix[0][j] as 0 whenever matrix[i][j] == 0.
 * 3. Iterate from (1, 1) and set matrix[i][j] = 0 if its row or col marker is 0.
 * 4. Finally update row 0 and col 0 if their respective flags were true.
 * 
 * TIME COMPLEXITY: O(M * N)
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
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    if (m == 0) return;
    int n = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if the first row contains zero
    for (int j = 0; j < n; j++)
    {
        if (matrix[0][j] == 0)
        {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column contains zero
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstColZero = true;
            break;
        }
    }

    // Mark zeros in the first row and column
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set cells to zero based on markers
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Set first row to zero
    if (firstRowZero)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[0][j] = 0;
        }
    }

    // Set first column to zero
    if (firstColZero)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int m, n;
    if (!(cin >> m >> n)) return;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    setZeroes(matrix);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
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
