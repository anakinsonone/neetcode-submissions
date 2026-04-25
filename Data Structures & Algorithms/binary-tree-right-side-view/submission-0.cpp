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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        deque<TreeNode*>dq;
        dq.push_back(root);

        while(!dq.empty()) {
            int s = dq.size();
            res.push_back(dq.back()->val);
            for(int i = 0; i < s; i++) {
                TreeNode* c = dq.front();
                dq.pop_front();

                if(c->left) {
                    dq.push_back(c->left);
                }
                if(c->right) {
                    dq.push_back(c->right);
                }
            }
        }
        return res;        
    }
};
