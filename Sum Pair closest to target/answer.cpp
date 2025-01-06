#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

vector<int> sumClosest(vector<int> &arr, int target)
{

    int n = arr.size();
    vector<int> resp;
    int i = 0, j = n - 1, minDiff = INT_MAX;
    sort(arr.begin(), arr.end());

    while (i < j)
    {

        int sum = arr[i] + arr[j];
        int diff = abs(target - sum);

        if (minDiff > diff)
        {
            minDiff = diff;
            resp = {arr[i], arr[j]};
        }

        if (sum < target)
        {
            i++;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            return resp;
        }
    }

    return resp;
}