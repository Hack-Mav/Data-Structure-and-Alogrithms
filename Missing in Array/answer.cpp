#include <vector>
using namespace std;


int missingNumber(vector<int>& arr) {
    int n = arr.size() + 1; // Since the array has n-1 elements, the size of the original range is n.
    vector<int> a(n + 1, 0); // Initialize an array with size n+1, filled with 0.
    
    // Mark the presence of numbers in the input array
    for (int i = 0; i < arr.size(); i++) {
        a[arr[i]] = 1;
    }
    
    // Find the missing number
    for (int i = 1; i <= n; i++) {
        if (a[i] != 1) {
            return i;
        }
    }
    return -1; // This line will never be reached if input is valid.
}

// Time Complexity: O(n)
// Space Complexity: O(n)   
