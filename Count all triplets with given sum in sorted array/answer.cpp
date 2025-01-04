#include <vector>
using namespace std;

int countTriplets(vector<int> &arr, int target)
{
    // Code Here

    int n = arr.size(), res = 0;

    for (int i = 0; i < n - 2; i++)
    {

        int j = i + 1, k = n - 1;

        while (j < k)
        {

            int sum = arr[i] + arr[j] + arr[k];

            if (sum - target < 0)
            {
                j++;
            }
            else if (sum - target > 0)
            {
                k--;
            }
            else if (sum - target == 0)
            {

                int left = arr[j], right = arr[k];
                int count1 = 0, count2 = 0;

                while (j <= k && left == arr[j])
                {
                    j++;
                    count1++;
                }

                while (j <= k && right == arr[k])
                {
                    k--;
                    count2++;
                }

                if (left == right)
                {
                    res += ((count1) * (count1 - 1)) / 2;
                }
                else
                {
                    res += (count1 * count2);
                }
            }
        }
    }

    return res;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
