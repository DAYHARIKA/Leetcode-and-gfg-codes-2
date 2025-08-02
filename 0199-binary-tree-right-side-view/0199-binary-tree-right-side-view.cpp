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
    void solve(TreeNode* root,vector<int> &ans,int level){
       
       if(root == NULL){
         return;
       }
       if(level==ans.size()){
         ans.push_back(root->val);
       }
       solve(root->right,ans,level+1);
       solve(root->left,ans,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        
       /* vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.empty() != 1){
            
            pair<TreeNode*,int> p=q.front();
            TreeNode *temp=p.first;
            int level=p.second;
            q.pop();
               
            mp[level]=temp->val;
            
            if(temp->left){
                q.push({temp->left,level+1});
            }
            if(temp->right){
                q.push({temp->right,level+1});
            }
        }
        
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }*/
    vector<int> ans;
    solve(root,ans,0);
    return ans;
    } 
};