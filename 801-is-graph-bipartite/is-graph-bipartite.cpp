class Solution {
public:
int n,m;
bool dfs(int node, vector<vector<int>>&adj, vector<int>&color){
    for(int i=0;i<adj[node].size();i++)
    {   int el = adj[node][i];
        if(color[el]==-1)
        {
            color[el] = (1+color[node])%2;
            if(!dfs(el,adj,color)) return false;
        }
        else {
            if(color[node]==color[el])
            return false;
        }
    }
    return true;
}

    bool isBipartite(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++)
            adj[i].push_back(graph[i][j]);
        }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
        if(dfs(i,adj,color)==0)
        return false;
        }
        return true;
    }
};

