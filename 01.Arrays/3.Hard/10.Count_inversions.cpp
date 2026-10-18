/**
 * Problem: Count Inversions in an Array
 * 
 * QUESTION:
 * Given an array of integers. Find the Inversion Count in the array.
 * Two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
 * 
 * Example:
 * Input: N = 5, arr[] = {2, 4, 1, 3, 5}
 * Output: 3
 * Explanation: Inversions are (2, 1), (4, 1), (4, 3).
 * 
 * APPROACH:
 * Enhanced Merge Sort:
 * -> Divide array into two halves, recursively sort and count inversions.
 * -> During merge: if left[i] > right[j], all remaining elements in left (leftsize - i)
 *    form inversions with right[j].
 * 
 * TIME COMPLEXITY: O(N log N)
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
long long mergeAndCount(vector<long long> &arr, int start, int mid, int end)
{
    int leftsize = mid - start + 1;
    int rightsize = end - mid;
    vector<long long> left(leftsize), right(rightsize);

    for (int i = 0; i < leftsize; i++) left[i] = arr[start + i];
    for (int i = 0; i < rightsize; i++) right[i] = arr[mid + 1 + i];

    long long count = 0;
    int i = 0, j = 0, k = start;

    while (i < leftsize && j < rightsize)
    {
        if (left[i] > right[j])
        {
            count += (leftsize - i);
            arr[k++] = right[j++];
        }
        else
        {
            arr[k++] = left[i++];
        }
    }

    while (i < leftsize) arr[k++] = left[i++];
    while (j < rightsize) arr[k++] = right[j++];

    return count;
}

long long mergeSortAndCount(vector<long long> &arr, int start, int end)
{
    long long count = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        count += mergeSortAndCount(arr, start, mid);
        count += mergeSortAndCount(arr, mid + 1, end);
        count += mergeAndCount(arr, start, mid, end);
    }
    return count;
}

long long inversionCount(vector<long long> &arr, int n)
{
    return mergeSortAndCount(arr, 0, n - 1);
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, n) << "\n";
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
