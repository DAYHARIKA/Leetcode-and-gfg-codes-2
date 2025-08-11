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
    int kthSmallest(TreeNode* root, int k) {
        
        TreeNode* root1=root;
        long cnt=0;
        int ans=-1;

        while(root1 != NULL){

            if(root1->left == NULL){
               cnt++;
               if(cnt == k){
                ans=root1->val;
               }
               root1=root1->right;
            }else{
                TreeNode* prev=root1->left;

                while(prev->right && prev->right != root1){
                    prev=prev->right;
                }

                if(prev->right == NULL){
                    prev->right = root1;
                    root1=root1->left;
                }else{
                    prev->right=NULL;
                    cnt++;
                    if(cnt == k){
                        ans=root1->val;
                    }
                    root1=root1->right;
                }
            }
        }
        return ans;
    }
};