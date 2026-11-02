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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q1;
        deque<TreeNode*>q2;
        int odd = 0;
        q1.push(root);
        while(!q1.empty()){
            int s = q1.size();
            if(odd%2==0){
               for(int i=0;i<s;i++){
                 TreeNode*temp = q1.front();
                 q1.pop();
                if(temp->left && temp->right){
                    q1.push(temp->left);
                    q1.push(temp->right);
                    q2.push_front(temp->left);
                    q2.push_front(temp->right);
                }
               }
            }
            else {
                  for(int i=0;i<s/2;i++){
                    TreeNode* f = q2.front();
                    TreeNode* sec = q2.back();
                    swap(f->val, sec->val);
                    q2.pop_front();
                    q2.pop_back();
                  }
                for(int i=0;i<s;i++){
                 TreeNode*temp = q1.front();
                 q1.pop();
                if(temp->left && temp->right){
                    q1.push(temp->left);
                    q1.push(temp->right);
                }
               }  
            }
            odd++;
        }
        return root;

    }
};