class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>>subsets;
       vector<int> sub;
       dfs(nums, 0, sub, subsets);
       return subsets; 
    }

    void dfs(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subsets) {
        if(i >= nums.size()) {
            subsets.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        dfs(nums, i + 1, sub, subsets);
        sub.pop_back();
        dfs(nums, i + 1, sub, subsets);
    }
};
