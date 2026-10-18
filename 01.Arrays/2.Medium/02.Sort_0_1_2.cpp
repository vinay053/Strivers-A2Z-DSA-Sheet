/**
 * Problem: Sort Colors (Sort 0s, 1s, and 2s / Dutch National Flag)
 * 
 * QUESTION:
 * Given an array nums with n objects colored red, white, or blue, sort them in-place
 * so that objects of the same color are adjacent, with the colors in the order red (0), white (1), and blue (2).
 * 
 * Example:
 * Input: nums = [2, 0, 2, 1, 1, 0]
 * Output: [0, 0, 1, 1, 2, 2]
 * 
 * APPROACH:
 * Dutch National Flag Algorithm:
 * -> Maintain 3 pointers: low = 0, mid = 0, high = n - 1.
 * -> If nums[mid] == 0: swap(nums[low], nums[mid]), low++, mid++
 * -> If nums[mid] == 1: mid++
 * -> If nums[mid] == 2: swap(nums[mid], nums[high]), high--
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
void sortColors(vector<int> &nums)
{
    int low = 0, mid = 0, high = (int)nums.size() - 1;
    while (mid <= high)
    {
        if (nums[mid] == 0)
            swap(nums[mid++], nums[low++]);
        else if (nums[mid] == 1)
            mid++;
        else
            swap(nums[mid], nums[high--]);
    }
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sortColors(nums);
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << (i == n - 1 ? "" : " ");
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