class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(int i = 0; i < strs.size(); i++) {
            string cpy = strs[i];
            sort(cpy.begin(), cpy.end());
            groups[cpy].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for(auto g: groups) {
            result.push_back(g.second);
        }
        return result;
    }
};
