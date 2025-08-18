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
    int countnodes(TreeNode* root){
        if(root == NULL)return 0;

        return 1+countnodes(root->left)+countnodes(root->right);
    }
    bool solve(TreeNode* root,int index,int cnt){
         
        if(root == NULL)return true;

        if(index >= cnt)return false;

        int left=solve(root->left,2*index+1,cnt);
        int right=solve(root->right,2*index+2,cnt);

        return left&&right;


    }
    bool isCompleteTree(TreeNode* root) {
        
        int cnt=countnodes(root);
        return solve(root,0,cnt);
    }
};