class Solution {
public:
    bool isAlphaNum(char c) {
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l <= r) {
            while (!isAlphaNum(s[l]) && l < r) l++;
            while (!isAlphaNum(s[r]) && r > l) r--;

            char lowL = tolower(s[l]);
            char lowR = tolower(s[r]);
            if (lowL != lowR)   return false;

            l++;
            r--;
        }

        return true;
    }
};
