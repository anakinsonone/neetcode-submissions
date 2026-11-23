class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int i = 0; i < nums.size(); i++) {
            counts[nums[i]]++;
        }

        map<int, vector<int>, greater<int>> ord_counts;
        for (auto c : counts) {
            ord_counts[c.second].push_back(c.first);
        }

        vector<int> result;
        for (auto p : ord_counts) {
            for(auto n: p.second) {
                result.push_back(n);
                if (result.size() == k) return result;
            }
            if (result.size() == k) return result;
        }

        return result;
    }
};
