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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});

        int first,last,ans=INT_MIN;

        while(!q.empty()){

            int s=q.size();
            int mini=q.front().second;

            for(int i=0;i<s;i++){
                TreeNode* node=q.front().first;
                int ind=q.front().second-mini;
                q.pop();
                if(i == 0)first=ind;
                if(i == s-1)last=ind;

                if(node->left)q.push({node->left,2LL*ind+1});
                if(node->right)q.push({node->right,2LL*ind+2});
            }

            ans=max(ans,last-first+1);
        }

        return ans;

    }
};