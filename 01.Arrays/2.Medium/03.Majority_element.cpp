/**
 * Problem: Majority Element (> n / 2 times)
 * 
 * QUESTION:
 * Given an array nums of size n, return the majority element.
 * The majority element is the element that appears more than ⌊n / 2⌋ times.
 * You may assume that the majority element always exists in the array.
 * 
 * Example:
 * Input: nums = [3, 2, 3]
 * Output: 3
 * 
 * APPROACH:
 * Moore's Voting Algorithm:
 * -> Initialize candidate = nums[0], count = 1.
 * -> For each element, if count == 0, set candidate = nums[i].
 * -> If element == candidate, count++, else count--.
 * -> The candidate at the end is the majority element.
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
int majorityElement(const vector<int> &nums)
{
    int candidate = nums[0];
    int vote = 1;
    for (int i = 1; i < (int)nums.size(); i++)
    {
        if (vote <= 0)
            candidate = nums[i];
        if (nums[i] == candidate)
            vote++;
        else
            vote--;
    }
    return candidate;
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
    cout << majorityElement(nums) << "\n";
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