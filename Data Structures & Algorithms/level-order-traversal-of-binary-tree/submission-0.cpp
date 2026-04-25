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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;

        deque<TreeNode*>dq;
        dq.push_back(root);

        while(!dq.empty()) {
            int size = dq.size();
            vector<int>level;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = dq.front();
                dq.pop_front();
                level.push_back(curr->val);

                if(curr->left) {
                    dq.push_back(curr->left);
                }
                if(curr->right) {
                    dq.push_back(curr->right);
                }
            }
            if(level.size()) {
                res.push_back(level);
            }
        }
        return res;
    }
};
