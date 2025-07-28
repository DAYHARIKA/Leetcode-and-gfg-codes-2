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
    int solve(TreeNode* root,int &maxi){
        if(root == NULL)return -1;

        int left=solve(root->left,maxi);
        int right=solve(root->right,maxi);

        maxi=max(maxi,left+1+right+1);

        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        solve(root,maxi);
        return maxi;
    }
};