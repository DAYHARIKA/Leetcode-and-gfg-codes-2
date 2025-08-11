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
    TreeNode* solve(TreeNode* &root, int val){
        if(root == NULL){
            root=new TreeNode(val);
        }else if(root->val < val){
            root->right=solve(root->right,val);
        }else{
            root->left=solve(root->left,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
         
        //  TreeNode* root1=root;
        //  TreeNode* prev=NULL;
        //  while(root1 != NULL){

        //     if(root1->val < val){
        //         prev=root1;
        //         root1=root1->right;
        //     }else{
        //         prev=root1;
        //         root1=root1->left;
        //     }
        //  }
         
        //  if(prev == NULL){
        //     root=new TreeNode(val);
        //  }else if(prev->val < val){
        //     prev->right=new TreeNode(val);
        //  }else{
        //     prev->left=new TreeNode(val);
        //  }
         solve(root,val);
         return root;
    }
};