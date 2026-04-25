class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int left = 0, right = 0;
        std::unordered_set<char> charSet;
        while (right < s.size() && left < s.size()) {
            if (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]);
            left++;
            } else {
                charSet.insert(s[right]);
                right++;
                res = std::max(res, (int)charSet.size());
            }
        }
        return res;
    }
};
