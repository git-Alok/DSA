class Solution {
public:
int ans =0;
int row[4] = {1,-1,0,0};
int col[4] = {0,0,1,-1};
void bfs(int i,int j,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j] = 0;
        while(!q.empty()){
           int u = q.front().first;
           int v = q.front().second;
           ans++;
           q.pop();
           for(int k=0;k<4;k++){
              int x = u+row[k];
              int y = v+col[k];
              if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1){
                grid[x][y] = 0;
                q.push({x,y});
              }
           }
        }
        return ;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
       for(int i=0;i<n;i++){
        if(grid[i][0]==1)
        bfs(i,0,grid);
        if(grid[i][m-1]==1)
        bfs(i,m-1,grid);
       }
       for(int j=0;j<m;j++){
        if(grid[0][j]==1)
        bfs(0,j,grid);
        if(grid[n-1][j]==1)
        bfs(n-1,j,grid);
       }
       ans =0;
       for(int i = 1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            if(grid[i][j]==1)
          bfs(i,j,grid);
        }
       }
       return ans;
    }
};