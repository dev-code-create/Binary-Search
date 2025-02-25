#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        int index = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow

            // If the current search space is already sorted
            if (nums[low] <= nums[high]) {
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                break; // Entire array is sorted, no need to continue
            }

            // If the left part is sorted
            if (nums[low] <= nums[mid]) {
                // Keep track of the minimum in the left part
                if (nums[low] < ans) {
                    index = low;
                    ans = nums[low];
                }
                // Eliminate the left part
                low = mid + 1;
            } 
            else { // If the right part is sorted
                // Keep track of the minimum in the right part
                if (nums[mid] < ans) {
                    index = mid;
                    ans = nums[mid];
                }
                // Eliminate the right part
                high = mid - 1;
            }
        }

        return index; // Return the index of the smallest element
    }
};