/**
 * Problem: Find Missing and Repeating Numbers
 * 
 * QUESTION:
 * Given an unsorted array Arr of size N of positive integers from 1 to N.
 * One number 'A' is missing and one number 'B' occurs twice in the array. Find these two numbers.
 * 
 * Example:
 * Input:
 * N = 2, Arr[] = {2, 2}
 * Output: 2 1
 * Explanation: Repeating number is 2 and missing number is 1.
 * 
 * APPROACH:
 * Math (Sum and Sum of Squares):
 * -> optSum = N * (N + 1) / 2
 * -> opt2Sum = N * (N + 1) * (2 * N + 1) / 6
 * -> x = missing, y = repeating
 * -> x - y = optSum - actSum
 * -> x^2 - y^2 = opt2Sum - act2Sum
 * -> x + y = (x^2 - y^2) / (x - y)
 * -> x = ((x + y) + (x - y)) / 2, y = (x + y) - x.
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
pair<int, int> findTwoElement(const vector<int> &arr, int N)
{
    long long n = N;
    long long optSum = n * (n + 1) / 2;
    long long opt2Sum = n * (n + 1) * (2 * n + 1) / 6;
    long long actSum = 0;
    long long act2Sum = 0;

    for (int it : arr)
    {
        actSum += it;
        act2Sum += (long long)it * it;
    }

    long long xMinusY = optSum - actSum;
    long long x2MinusY2 = opt2Sum - act2Sum;
    long long xPlusY = x2MinusY2 / xMinusY;

    long long x = (xPlusY + xMinusY) / 2; // missing
    long long y = xPlusY - x;              // repeating

    return {(int)y, (int)x};
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
    auto [repeating, missing] = findTwoElement(arr, n);
    cout << repeating << " " << missing << "\n";
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
