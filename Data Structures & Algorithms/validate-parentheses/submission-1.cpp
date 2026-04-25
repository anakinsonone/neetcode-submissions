class Solution {
public:
    bool isClosingBracket(char c) {
        if(c == ']' || c == ')' || c == '}') return true;
        else return false;
    }

    char getOpeningBracket(char c) {
        switch (c) {
            case ')': return '(';
            case ']': return '[';
            case '}': return '{';
            default: return ' ';
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(st.size() == 0 || !isClosingBracket(s[i]))
                st.push(s[i]);
            else if (isClosingBracket(s[i]) && st.top() == getOpeningBracket(s[i])) {
                st.pop();
            } else {
                return false;
            }
        } 
        if (st.size() != 0) return false;
        else return true;
    }
};
