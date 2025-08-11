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
    TreeNode* getRight(TreeNode* root){

        while(root->left != NULL){
            root=root->left;
        }

        return root;
    }
    TreeNode* solve(TreeNode* &root, int key){

        if(root == NULL)return root;

        if(root->val == key){

            if(root->left == NULL && root->right == NULL){
                return NULL;
            }else if(root->left != NULL && root->right == NULL){
               TreeNode* temp=root->left;
               delete root;
               return temp;
            }else if(root->left == NULL && root->right != NULL){
               TreeNode* temp=root->right;
               delete root;
               return temp;
            }else{
                TreeNode* temp=getRight(root->right);
                root->val=temp->val;
                root->right=solve(root->right,temp->val);
                return root;
            }


        }else if(root->val < key){
            root->right=solve(root->right,key);
            return root;
        }else{
            root->left=solve(root->left,key);
            return root;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root=solve(root,key);
        return root;
    }
};