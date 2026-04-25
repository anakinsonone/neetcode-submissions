class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       vector<int> cur;
       sort(candidates.begin(), candidates.end());
       dfs(candidates, target, cur, 0);
       return res; 
    }
    void dfs(vector<int>& nums, int target, vector<int>& cur, int i) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        if(target < 0 || i >= nums.size()) {
            return;
        }
        cur.push_back(nums[i]);
        dfs(nums, target - nums[i], cur, i + 1);
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        cur.pop_back();
        dfs(nums, target, cur, i + 1);
    }
};
