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
    void solve(TreeNode* root,vector<vector<int>>& ans){

        queue<TreeNode*> q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> arr(size);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                int index=(cnt%2 == 0)?i:size-1-i;
                arr[index]=temp->val;
                if(temp->left)q.push(temp->left);  
                if(temp->right)q.push(temp->right);
            }
            ans.push_back(arr);
            cnt++;
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root == NULL)return ans;
        solve(root,ans);
        return ans;
    }
};