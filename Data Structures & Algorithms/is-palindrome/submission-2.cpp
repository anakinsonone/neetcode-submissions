class Solution {
public:
    std::string processString(std::string s) {
        std::string sanitizedS;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
            char c = std::tolower(s[i]);
            sanitizedS += c;
            }
        }

        std::cout << sanitizedS << '\n';
        return sanitizedS;
    }

    bool isPalindrome(string s) {
        s = processString(s);

        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j])
            return false;
            i++;
            j--;
        }

        return true;
    }
};
