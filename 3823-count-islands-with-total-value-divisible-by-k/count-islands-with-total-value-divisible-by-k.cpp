class Solution {
public:
int row[4] = {1,-1, 0,0};
int col[4] = {0,0, 1,-1};
long long bfs(int i, int j, int n, int m, vector<vector<int>>&grid){
    long long sum = 0;
    queue<pair<int,int>>q;
    q.push({i,j});
    sum+=grid[i][j];
    grid[i][j] = 0;
    while(!q.empty()){
        int f = q.front().first;
        int s = q.front().second;
        q.pop();
        for(int k =0 ;k<4;k++){
            int x = f+row[k];
            int y = s+col[k];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]>0){
                q.push({x,y});
                sum+=grid[x][y];
                grid[x][y] =0;
            }
        }
    }
    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
             long long  temp = bfs(i,j,n,m,grid);
             if(temp%k==0) ans++;
         }
            }
        }
        return ans;
    }
};