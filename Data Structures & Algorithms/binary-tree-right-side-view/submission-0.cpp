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
        if(root==NULL){
            return {};
        }
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int levelSize=q.size();
            vector<int> res;
            for(int i=0;i<levelSize;i++){
                TreeNode* curr=q.front();
                q.pop();
                res.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            levels.push_back(res);
        }
        return levels;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> levels=levelOrder(root);
        vector<int> res;
        for(int i=0;i<levels.size();i++){
            vector<int> l=levels[i];
            int n=l.size();
            res.push_back(l[n-1]);
        }
        return res;
    }
};
