#include <vector>
using namespace std;

int maxSubarraySum(vector<int> &arr)
{
    // code here...

    int n = arr.size(), maxEnding = arr[0], response = arr[0];

    for (int i = 1; i < n; i++)
    {

        // Find the maxEnding upto ith index either by appending the arr[i] to maxEnding of (i-1)th or starting
        // a new subarray from arr[i].
        maxEnding = max(maxEnding + arr[i], arr[i]);

        // Update the response if maxEnding is greater than response.
        response = max(response, maxEnding);
    }

    return response;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
