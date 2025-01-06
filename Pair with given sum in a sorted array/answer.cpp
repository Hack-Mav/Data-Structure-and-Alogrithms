#include <vector>
using namespace std;

int countPairs(vector<int> &arr, int target)
{
    // Complete the function

    int n = arr.size(), numberOfPairs = 0;
    int left = 0, right = n - 1;

    while (left < right)
    {

        if (arr[left] + arr[right] == target)
        {
            int ele1 = arr[left], ele2 = arr[right];
            int count1 = 0, count2 = 0;

            while (left <= right && ele1 == arr[left])
            {
                count1++;
                left++;
            }

            while (left <= right && ele2 == arr[right])
            {
                count2++;
                right--;
            }

            if (ele1 == ele2)
            {
                numberOfPairs += ((count1) * (count1 - 1)) / 2;
            }
            else
            {
                numberOfPairs += (count1) * (count2);
            }
        }
        else if (arr[left] + arr[right] > target)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    return numberOfPairs;
}