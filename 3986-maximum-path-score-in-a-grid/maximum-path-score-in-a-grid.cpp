class Solution {
public:
map<int,int> score = {
    {0,0}, {1,1}, {2,2}
};
map<int,int> cost = {
    {0,0}, {1,1}, {2,1}
};
int dfs(int i,int j,int n,int m,vector<vector<int>>&grid,int k,int c,vector<vector<vector<int>>>&dp){
    if(c>k) return -100000;
    if(i==n-1 && j==m-1) { 
        if(c+cost[grid[i][j]]<=k) return score[grid[i][j]];
        else return -100000;
    }
    if(i>=n || j>=m) return -100000;
    if(dp[i][j][c]!=-1) return  dp[i][j][c];
    int r=score[grid[i][j]]+dfs(i,j+1,n,m,grid,k,c+cost[grid[i][j]],dp);
    int d=score[grid[i][j]]+dfs(i+1,j,n,m,grid,k,c+cost[grid[i][j]],dp);
    return dp[i][j][c]=max(r,d);
}

    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(400, -1)));
        int c=0;
     int ans= dfs(0,0,n,m,grid,k,c,dp);
     if(ans<0) return -1;
     return ans;
    }
};