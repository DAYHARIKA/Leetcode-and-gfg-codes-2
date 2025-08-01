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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(q.empty()!=1){

            pair<TreeNode*,pair<int,int>> temp=q.front();
            q.pop();
            TreeNode* node=temp.first;
            int vert=temp.second.first;
            int levl=temp.second.second;
            //storing in map
            nodes[vert][levl].insert(node->val);
            
            if(node->left != NULL){
                q.push(make_pair(node->left,make_pair(vert-1,levl+1)));
            }
            if(node->right != NULL){
                q.push(make_pair(node->right,make_pair(vert+1,levl+1)));
            }
        }
        
        for(auto i:nodes){
             vector<int> ans1;
            for(auto j:i.second){
                for(auto k:j.second){
                    ans1 .push_back(k);
                }
            }
            ans.push_back(ans1);
        }
        return ans;
    }
};