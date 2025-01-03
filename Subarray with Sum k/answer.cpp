#include <vector>
#include <unordered_map>
using namespace std;

int countSubarrays(vector<int> &arr, int k)
{
    int n = arr.size(), currSum = 0, total_count = 0;
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {

        currSum += arr[i];

        if (currSum == k)
        {
            total_count += 1;
        }

        if (ump.find(currSum - k) != ump.end())
        {
            total_count += ump[currSum - k];
        }

        ump[currSum]++;
    }

    return total_count;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

