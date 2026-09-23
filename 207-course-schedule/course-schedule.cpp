class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>inorder(numCourses,0);
        int e = prerequisites.size();
        for(int i=0;i<e;i++)
        {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
            inorder[v]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int i=0;i<adj[top].size();i++){
                inorder[adj[top][i]]--;
                if(inorder[adj[top][i]]==0)
                q.push(adj[top][i]);
            }
        }
        for(auto num : inorder)
        {
            if(num>0) return false;
        }
        return true;
    }
};