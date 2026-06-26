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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        map<int,map<int,multiset<int>>>m;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* curr = q.front().first;
            int level = q.front().second.first;
            int vertical=q.front().second.second;
            q.pop();
            m[vertical][level].insert(curr->val);
            if(curr->left != NULL){
                q.push({curr->left,{level+1,vertical-1}});
            }
            if(curr->right != NULL){
                q.push({curr->right,{level+1,vertical+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto &v : m){
            vector<int>temp;
            for(auto &lvl : v.second){
                for(int val : lvl.second){
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};