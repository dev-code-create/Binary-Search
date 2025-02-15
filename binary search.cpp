#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;

    // Standard binary search loop
    while (left <= right)
    {
      // Prevent potential overflow:
      int mid = left + (right - left) / 2;

      // Check if the mid element is the target
      if (nums[mid] == target)
        return mid;
      // If target is greater, ignore left half
      else if (nums[mid] < target)
        left = mid + 1;
      // If target is smaller, ignore right half
      else
        right = mid - 1;
    }

    // Target not found
    return -1;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 5;
  int result = sol.search(nums, target);
  cout << "Index of target " << target << " is: " << result << endl;
  return 0;
}
