class Solution {
public:
    vector<vector<int>>res;
    void dfs(vector<int>& nums, vector<int>& sub, int i) {
        if(i == nums.size()) {
            res.push_back(sub);
            return;
        }

        sub.push_back(nums[i]);
        dfs(nums, sub, i + 1);
        sub.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i + 1]) i++;
        dfs(nums, sub, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>sub;
        dfs(nums, sub, 0);
        return res;
    }
};
