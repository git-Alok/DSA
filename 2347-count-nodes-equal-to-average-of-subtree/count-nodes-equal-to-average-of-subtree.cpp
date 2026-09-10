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
int ans =0;
pair<int,int> fun(TreeNode*root){
    if(root==NULL) return {0,0};
    pair<int,int>p1 = fun(root->left);
    pair<int,int>p2 = fun(root->right);
   int sum = p1.first+p2.first;
   int count = p1.second+p2.second;
    int avg = (sum+root->val)/(count+1);
    if(root->val==avg)
    ans++;
    return {sum+root->val,count+1};

}
    int averageOfSubtree(TreeNode* root) {
        fun(root);
        return ans;
    }
};