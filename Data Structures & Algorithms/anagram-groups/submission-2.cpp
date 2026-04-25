class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> answer;

        for(auto &s: strs) {
            vector<int> count(26, 0);

            for(auto c: s) {
                count[c - 'a']++;
            }

            string key;
            for(int i: count) {
                key += "#" + to_string(i);
            }

            answer[key].push_back(s);
        }

        vector<vector<string>> result;
        for(auto &it: answer){
            result.push_back(it.second);
        }

        return result;
    }
};
