#include <vector>
#include <climits>
using namespace std;

// Recursive Approach

int minJumpsRecur(int idx, vector<int> &arr, vector<int> &memo)
{

    if (idx == arr.size() - 1)
    {
        return 0;
    }

    if (memo[idx] != -1)
        return memo[idx];

    int ans = INT_MAX;
    for (int i = idx + 1; i <= idx + arr[idx] && i < arr.size(); i++)
    {
        int val = minJumpsRecur(i, arr, memo);
        if (val != INT_MAX)
        {
            ans = min(ans, val + 1);
        }
    }

    return memo[idx] = ans;
}

int minJumps(vector<int> &arr)
{
    // code here

    vector<int> memo(arr.size(), -1);

    int ans = minJumpsRecur(0, arr, memo);

    if (ans == INT_MAX)
    {
        return -1;
    }

    return ans;
}

// Time Complexity: O(n^2) [Memoization/ Top Down Approach]
// Space Complexity: O(n)

// ==============================

// Optimized Approach

int minJumps(vector<int> &arr)
{
    // code here

    int n = arr.size();

    if (n <= 1)
    {
        return 0;
    }

    if (arr[0] == 0)
    {
        return -1;
    }

    int maxReach = arr[0];
    int step = arr[0];
    int jump = 1;

    for (int i = 1; i < n; i++)
    {

        if (i == n - 1)
        {
            return jump;
        }

        maxReach = max(maxReach, i + arr[i]);

        step--;

        if (step == 0)
        {

            jump++;

            if (i >= maxReach)
            {
                return -1;
            }

            step = maxReach - i;
        }
    }

    return -1;
}

// Time Complexity: O(n) [Greedy Approach]
// Space Complexity: O(1)
