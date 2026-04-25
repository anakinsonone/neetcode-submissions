/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int c = 0;
        if(!root) return c;

        stack<pair<TreeNode*, int>>st;
        st.push({root, root->val});

        while(!st.empty()) {
            pair<TreeNode*, int> curr = st.top();
            st.pop();

            if(curr.first->val >= curr.second) c++;

            if(curr.first->left) st.push({curr.first->left, max(curr.first->val, curr.second)});
            if(curr.first->right) st.push({curr.first->right, max(curr.first->val, curr.second)});
        }

        return c;
    }
};
