class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) {
            return "";
        }

        std::unordered_map<char, int> tCharMap, window;
        for (char c : t) {
            tCharMap[c]++;
        }

        int l = 0, resLen = INT_MAX, have = 0, need = tCharMap.size();
        pair<int, int>res{-1, -1};
        for(int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if(tCharMap.count(c) && window[c] == tCharMap[c]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < resLen) {
                    res = {l, r};
                    resLen = r - l + 1;
                }

                window[s[l]]--;
                if(tCharMap.count(s[l]) && window[s[l]] < tCharMap[s[l]]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
