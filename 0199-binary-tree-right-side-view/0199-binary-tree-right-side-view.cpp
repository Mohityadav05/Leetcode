// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     void recursion(TreeNode* root,int level,vector<int>& res){
//         if(root==NULL){
//             return ;
//         }
//         if(res.size()==level) res.push_back(root->val);
//         recursion(root->right,level+1,res);
//         recursion(root->left,level+1,res);
//     }
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int>res;
//         recursion(root,0,res);
//         return res;
//     }
// };
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (root == NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Last node of this level
                if (i == n - 1) {
                    res.push_back(node->val);
                }

                if (node->left != NULL) {
                    q.push(node->left);
                }

                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
        }

        return res;
    }
};