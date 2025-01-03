#include <vector>
#include <unordered_map>
using namespace std;

int majorityElement(vector<int> &arr)
{

    unordered_map<int, int> ump;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {

        ump[arr[i]]++;
    }

    for (auto x : ump)
    {

        if (x.second > n / 2)
        {
            return x.first;
        }
    }

    return -1;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

// ================================
// Using Moore's Voting Algorithm

int majorityElement(vector<int> &arr)
{

    int n = arr.size(), count = 0, candidate;

    // Step-1: Find candidate which may be a majority element
    for (int i = 0; i < n; i++)
    {

        if (count == 0)
        {
            candidate = arr[i];
        }

        count += arr[i] == candidate ? 1 : -1;
    }

    // Step-2: Verify the candidate that it is in majority
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    // Step-3: Check if selected element is in majority
    if (count > n / 2)
    {
        return candidate;
    }

    return -1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
