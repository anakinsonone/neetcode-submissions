class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        vector<vector<int>> freq(nums.size() + 1);

        for(auto n: nums) {
            counts[n]++;
        }

        for(auto &pair: counts) {
            freq[pair.second].push_back(pair.first);
        }

        vector<int> res;
        for(int i = freq.size() - 1; i > 0; i--) {
            for(int n: freq[i]) {
                res.push_back(n);
                if(res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};
