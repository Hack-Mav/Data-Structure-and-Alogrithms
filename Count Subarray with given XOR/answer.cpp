#include <vector>
#include <unordered_map>
using namespace std;

long subarrayXor(vector<int> &arr, int k)
{
    // code here

    unordered_map<int, int> ump;
    int n = arr.size(), total_cnt = 0, elementsxor = 0;

    for (int i = 0; i < n; i++)
    {

        elementsxor = elementsxor xor arr[i];

        if (elementsxor == k)
        {
            total_cnt++;
        }

        if (ump.find(elementsxor xor k) != ump.end())
        {
            total_cnt += ump[elementsxor xor k];
        }

        ump[elementsxor]++;
    }

    return total_cnt;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

