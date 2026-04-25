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
    int kthSmallest(TreeNode* root, int k) {
        deque<TreeNode*>dq;
        dq.push_back(root);

        set<int>st;
        while(!dq.empty()) {
            TreeNode* curr = dq.front();
            dq.pop_front();

            st.insert(curr->val);

            if(curr->left) dq.push_back(curr->left);
            if(curr->right) dq.push_back(curr->right);
        }

        int c = 1;
        for(int i: st) {
            if(c == k) return i;
            c++;
        }
    }
};
