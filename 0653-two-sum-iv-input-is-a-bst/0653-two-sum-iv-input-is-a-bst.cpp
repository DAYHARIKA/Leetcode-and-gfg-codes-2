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
class bstIterator{
private:
    stack<TreeNode*> st;
    bool rev=true;
    void allnodes(TreeNode* root,bool Reverse){
        while(root != NULL){
            st.push(root);
            if(Reverse)root=root->right;
            else root=root->left;
        }
    }
public:
    bstIterator(TreeNode* root,bool Reverse){
       rev=Reverse;
       allnodes(root,Reverse);
    }
    int next(){
        TreeNode* temp=st.top();
        st.pop();
        if(rev == true){
            if(temp->left){
                allnodes(temp->left,rev);
            }
        }else{
            if(temp->right){
                allnodes(temp->right,rev);
            } 
        }

        return temp->val;

    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
         
         bstIterator b1(root,false);
         bstIterator b2(root,true);
         
         int i=b1.next();
         int j=b2.next();

         while(i<j){

            if(i+j == k){
                return true;
            }else if(i+j < k){
                i=b1.next();
            }else{
                j=b2.next();
            }
         }

         return false;

    }
};