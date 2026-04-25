class Solution {
public:
    string minWindow(string s, string t) {
    if (s.length() < t.length()) {
        return "";
    }

    std::unordered_map<char, int> tCharMap;
    for (char c : t) {
        tCharMap[c]++;
    }

    std::string res = "";
    int minLen = INT_MAX;
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            if (j - i + 1 < t.length()) {
                continue;
            }

            std::unordered_map<char, int> subCharMap;
            for (int k = i; k <= j; k++) {
                subCharMap[s[k]]++;
            }

            bool contains = true;
            for (char c : t) {
                if (subCharMap[c] < tCharMap[c]) {
                contains = false;
                break;
                }
            }

            if (contains && j - i + 1 < minLen) {
                res = s.substr(i, j - i + 1);
                minLen = j - i + 1;
            }
        }
    }

    return res; 
    }
};
