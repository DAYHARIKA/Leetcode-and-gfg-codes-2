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
private:
    void inorder(TreeNode* &root,TreeNode* &first,TreeNode* &middle,TreeNode* &last,TreeNode* &prev){

         if(root == NULL)return;

         inorder(root->left,first,middle,last,prev);

         if(prev != NULL && root->val < prev->val){

            if(first == NULL){
                first=prev;
                middle=root;
            }else{
                last=root;
            }
         }

         prev=root;

         inorder(root->right,first,middle,last,prev);
    }
public:
    void recoverTree(TreeNode* root) {
         
        TreeNode* first=NULL;
        TreeNode* last =NULL;
        TreeNode* middle=NULL;
        TreeNode* prev=NULL;
        inorder(root,first,middle,last,prev);

        if(first && last)swap(first->val,last->val);
        else if(first && middle)swap(first->val,middle->val);
    }
};