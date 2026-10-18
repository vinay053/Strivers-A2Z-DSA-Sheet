/**
 * Problem: Merge Overlapping Intervals
 * 
 * QUESTION:
 * Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals
 * and return an array of non-overlapping intervals that cover all the intervals in the input.
 * 
 * Example:
 * Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
 * 
 * APPROACH:
 * 1. Sort the intervals based on the start time.
 * 2. Push the first interval to ans.
 * 3. For each subsequent interval:
 *    - If ans.back()[1] >= intervals[i][0], merge by taking max of end times.
 *    - Otherwise, push intervals[i] as a new non-overlapping interval.
 * 
 * TIME COMPLEXITY: O(N log N)
 * SPACE COMPLEXITY: O(N) (for storing output)
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
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);

    for (int i = 1; i < (int)intervals.size(); i++)
    {
        if (ans.back()[1] >= intervals[i][0])
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        else
        {
            ans.push_back(intervals[i]);
        }
    }

    return ans;
}

// ---------------------- CP DRIVER / SOLVE ----------------------
void solve()
{
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> res = merge(intervals);
    cout << res.size() << "\n";
    for (const auto &iv : res)
    {
        cout << iv[0] << " " << iv[1] << "\n";
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
