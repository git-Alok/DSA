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
int gethl(TreeNode*root){
if(!root) return 0;
   return 1+ gethl(root->left);
}
int gethr(TreeNode*root){
if(!root) return 0;
   return 1+ gethr(root->right);
}
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int l = gethl(root);
        int r = gethr(root);
        if(l==r) return pow(2,l)-1;
        return 1+countNodes(root->left) + countNodes(root->right);
    }
};