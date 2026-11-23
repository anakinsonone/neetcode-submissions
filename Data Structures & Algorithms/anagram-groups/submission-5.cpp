class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anas;
        for(int i = 0; i < strs.size(); i++) {
            string ana = strs[i];
            sort(ana.begin(), ana.end());
            anas[ana].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto a: anas) {
            result.push_back(a.second);
        }

        return result;
    }
};
