#include <vector>
#include <algorithm>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    // Your code here

    int n = arr.size(), resp = 0;
    int i = 0, j = n - 1;
    sort(arr.begin(), arr.end());

    while (i < j)
    {

        if (arr[i] + arr[j] >= target)
        {
            j--;
        }
        else
        {
            resp += (j - i);
            i++;
        }
    }

    return resp;
}