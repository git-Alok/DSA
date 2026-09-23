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
int cal(TreeNode*root,TreeNode*dub){
    if(!root) return 0;
    if(dub->val!=-1) return dub->val;
    int take = root->val;
    if(root->left)
    take+=cal(root->left->left,dub->left->left)+cal(root->left->right,dub->left->right);
    if(root->right)
    take+=cal(root->right->right,dub->right->right)+cal(root->right->left,dub->right->left);

    int skip = cal(root->left,dub->left)+ cal(root->right,dub->right);
    return dub->val = max(take,skip);
}
void build(TreeNode*root,TreeNode*dub){
    if(!root) return ;
    if(root->left)
    {
        dub->left = new TreeNode(-1);
    }
     build(root->left,dub->left);
    if(root->right){
       dub->right = new TreeNode(-1);
    }
    build(root->right, dub->right);
}
    int rob(TreeNode* root) {
        TreeNode*root2 = new TreeNode(-1);
        TreeNode*dub = root2;
        build(root,root2);
       return cal(root,dub);
    }
};