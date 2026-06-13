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
    int height(TreeNode*  root){

        if(root == NULL)return 0;

        int left=height(root->left);

        int right=height(root->right);

        return max(left,right)+1;
    }
    int solve(TreeNode*  root){
        
        if(root == NULL)return 0;

        int leftdia=solve(root->left);
        int rigthdia=solve(root->right);

        return max(leftdia,max(rigthdia,height(root->left)+height(root->right)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        return solve(root);
    }
};