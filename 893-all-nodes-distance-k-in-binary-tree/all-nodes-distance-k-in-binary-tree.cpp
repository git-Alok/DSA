/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void inorder(TreeNode*root, map<TreeNode*,TreeNode*>&parent){
    if(!root) return ;
    if(root->left)
     parent[root->left] = root;
    inorder(root->left,parent);
    if(root->right)
     parent[root->right] = root;
    inorder(root->right,parent);
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        inorder(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        int level = 0;
        vector<int>ans;
        set<TreeNode*>visit;
        visit.insert(target);
        while(!q.empty()){
            int n = q.size();
            if(level==k) break;
            while(n--){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left && !visit.count(temp->left)){
                    q.push(temp->left);
                    visit.insert(temp->left);
                }
                if(temp->right && !visit.count(temp->right)){
                    q.push(temp->right);
                    visit.insert(temp->right);
                }
                if(parent[temp] && !visit.count(parent[temp])){
                    q.push(parent[temp]);
                    visit.insert(parent[temp]);
                }
            }
            level++;
        }
        cout<<q.size()<<endl;
       while(!q.empty()){
        int value = q.front()->val;
        q.pop();
        ans.push_back(value);
       }
       return ans;
    }
};