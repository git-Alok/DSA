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
TreeNode* insert(TreeNode*&root,int item){
    if(!root) {
        root = new TreeNode(item);
        return root;
    }
    if(root->val<item)
     insert(root->right,item);
    else 
     insert(root->left,item);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode*root = NULL;
        for(int i=0;i<preorder.size();i++)
       insert(root,preorder[i]);
        return root;
    }
};