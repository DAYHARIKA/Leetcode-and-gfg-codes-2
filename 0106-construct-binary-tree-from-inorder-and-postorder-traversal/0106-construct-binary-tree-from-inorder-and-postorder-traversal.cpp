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
    TreeNode* solve(vector<int>& inorder, int instart,int inend,vector<int>& postorder,int poststart,int postend,unordered_map<int,int> &mp){

        if(instart > inend || poststart > postend)return NULL;

        int inroot=mp[postorder[postend]];
        int num=inend-inroot;

        TreeNode* root=new TreeNode(postorder[postend]);
        root->left=solve(inorder,instart,inroot-1,postorder,poststart,postend-num-1,mp);
        root->right=solve(inorder,inroot+1,inend,postorder,postend-num,postend-1,mp);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n1=inorder.size();
        int n2=postorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n1;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(inorder,0,n1-1,postorder,0,n2-1,mp);
        return root;
    }
};