class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> uniq;
        for (int i = 0; i < nums.size(); i++) {
            if (uniq.find(nums[i]) != uniq.end()){
                return true;
            } else {
                uniq.insert(nums[i]);
            }
        }
        return false;
    }
};