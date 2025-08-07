/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findnodes(TreeNode* root,int dist,vector<int> &ans){
         if(root == NULL)return;

         if(dist == 0){
            ans.push_back(root->val);
            return;
         }

         findnodes(root->left,dist-1,ans);
         findnodes(root->right,dist-1,ans);
    }
    int solve(TreeNode* root, TreeNode* target, int k,vector<int> &ans){
        
        if(root == NULL)return -1;

        if(root == target){
            findnodes(root,k,ans);
            return 1;
        }

        int left=solve(root->left,target,k,ans);

        if(left != -1){
            if(k-left == 0)ans.push_back(root->val);
            else findnodes(root->right,k-left-1,ans);
            return left+1;
        }
        
        int right=solve(root->right,target,k,ans);

        if(right != -1){
            if(k-right == 0)ans.push_back(root->val);
            else findnodes(root->left,k-right-1,ans);
            return right+1;
        }

        return -1;

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        vector<int> ans;
        solve(root,target,k,ans);
        return ans;
    }
};