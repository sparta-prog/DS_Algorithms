#include <iostream>
#include <vector>

using namespace std;
/*There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();

        if(n == 0)
            return false;

        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) {
                return true;
            }
            
            //remove the condition
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            else if(nums[low] <= nums[mid]) {
                //left half sorted
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

            else {
                //right half sorted
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return false;
    }
};

int main() {

    Solution obj;

    vector<int> data1 = {2,5,6,0,0,1,2};
    int target1 = 0;

    cout<<obj.search(data1,target1)<<endl;

    vector<int> data2 = {2,5,6,0,0,1,2};
    int target2 = 3;

    cout<<obj.search(data2,target2)<<endl;

    vector<int> data3 = {5,1,1,1,1,3};
    int target3 = 5;

    cout<<obj.search(data3,target3)<<endl;
}