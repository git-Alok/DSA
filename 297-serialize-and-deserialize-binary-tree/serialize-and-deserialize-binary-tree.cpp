/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s;
        queue<TreeNode*>q;
        q.push(root);
        s = to_string(root->val)+',';
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp = q.front();
                q.pop();
                if(temp->left){
                    s+=(to_string(temp->left->val)+',');
                    q.push(temp->left);
                }
                else s+='#,';
                if(temp->right){
                    s+=(to_string(temp->right->val)+',');
                    q.push(temp->right);
                }
                else 
                s+='#,';
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode*ans = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(ans);
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode*temp = q.front();
                q.pop();
                getline(s,str,',');
                if(str=="#") temp->left=NULL;
                else {
                    if(str!=""){
                    TreeNode*x = new TreeNode(stoi(str));
                    temp->left = x;
                    q.push(temp->left);
                    }
                }

                getline(s,str,',');
                if(str=="#") temp->right = NULL;
                else {
                    if(str!=""){
                    TreeNode*x = new TreeNode(stoi(str));
                    temp->right = x;
                    q.push(temp->right);
                    }
                }
            }
        }
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));