/**
 * Problem: Merge Sorted Array (Without Extra Space)
 * 
 * QUESTION:
 * You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
 * Merge nums1 and nums2 into nums1 as one sorted array in-place.
 * 
 * Example:
 * Input: nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
 * Output: [1, 2, 2, 3, 5, 6]
 * 
 * APPROACH:
 * Three pointers from the back:
 * -> i = m - 1 (end of valid nums1), j = n - 1 (end of nums2), k = m + n - 1 (end of buffer).
 * -> Compare nums1[i] and nums2[j], place larger at nums1[k], and decrement pointers.
 * -> Copy any remaining elements from nums2 into nums1.
 * 
 * TIME COMPLEXITY: O(M + N)
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
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int m, n;
    if (!(cin >> m >> n)) return;
    vector<int> nums1(m + n);
    for (int i = 0; i < m; i++) cin >> nums1[i];
    vector<int> nums2(n);
    for (int i = 0; i < n; i++) cin >> nums2[i];

    merge(nums1, m, nums2, n);
    for (int i = 0; i < m + n; i++)
    {
        cout << nums1[i] << (i == m + n - 1 ? "" : " ");
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
