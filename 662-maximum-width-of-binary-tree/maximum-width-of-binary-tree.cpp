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
typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
          queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll  ans=1;
        while(!q.empty()){
            ll s=q.size();
            ll x = q.front().second;
            ll y = q.back().second;
            ans = max(ans,y-x+1);
            for(int i=0;i<s;i++){
                TreeNode*temp= q.front().first;
                ll t= q.front().second;
                q.pop();
                if(temp->left){
                    q.push({temp->left,2*t+1});
                }
                if(temp->right){
                    q.push({temp->right,2*t+2});
                }
            }
        }
    return ans;
        
    }
};