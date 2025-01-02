#include <vector>
using namespace std;

vector<int> subarraySum(vector<int> &arr, int target)
{
    // code here
    int i = 0, n = arr.size();

    while (i < n)
    {

        int j = i, sum = 0;

        for (j; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
            {
                return {i + 1, j + 1};
            }
        }
        i++;
    }

    return {-1};
}