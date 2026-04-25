class Solution {
public:
    int characterReplacement(string s, int k) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        std::unordered_map<char, int> charMap;
        int maxF = 0;
        for (int j = i; j < s.size(); j++) {
        // increment count for char in this substring
        charMap[s[j]]++;
        // find the char with maxFreq
        maxF = std::max(maxF, charMap[s[j]]);
        if ((j - i + 1) - maxF <= k) {
            res = std::max(res, (j - i + 1));
        }
        }
    }
 
 return res;
    }
};
