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
map<int,map<int,vector<int>>>mp;
void trav(TreeNode*root,int row,int col){
    if(!root) return ;
    mp[col][row].push_back(root->val);
    trav(root->left,row+1,col-1);
    trav(root->right,row+1,col+1);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        trav(root,0,0);
     for(auto it = mp.begin();it!=mp.end();it++){
        map<int,vector<int>>temp = it->second;
        vector<int>arr;
        for(auto it2 = temp.begin();it2 != temp.end();it2++){
        vector<int>arr2 = it2->second;
            if(arr2.size()>1)
            sort(arr2.begin(),arr2.end());
            for(auto num : arr2)
            arr.push_back(num);
        }
       ans.push_back(arr);
     }
     return ans;
    }
};