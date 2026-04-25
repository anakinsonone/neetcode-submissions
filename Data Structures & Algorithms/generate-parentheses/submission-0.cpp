class Solution {
private: 
    void backtrack(int n, int openedN, int closedN, string current, vector<string> &result) {
        if(openedN == closedN && openedN == n) {
            result.push_back(current);
            return;
        }

        if(openedN < n) {
            backtrack(n, openedN + 1, closedN, current + "(", result);
        }

        if(closedN < openedN) {
            backtrack(n, openedN, closedN + 1, current + ")", result);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result; 
    }
};
