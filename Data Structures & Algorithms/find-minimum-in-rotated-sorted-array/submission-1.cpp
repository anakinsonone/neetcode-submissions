class Solution {
public:
    int findMin(vector<int> &nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        if (nums[low] > nums[high]) {
        low++;
        }
        if (nums[low] < nums[high]) {
        break;
        }
    }

    return nums[low]; 
    }
};
