class Solution {
public:
int row[4] = {1,-1,0,0};
int col[4] = {0,0,1,-1};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans =0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 ){
                 queue<pair<int,int>>q;
                 q.push({i,j});
                 grid[i][j] =0;
                 int count =0;
                 while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    count++;
                    for(int k=0;k<4;k++){
                      int px = x+row[k];
                      int py = y+col[k];
                      if(px>=0 && px<n && py>=0 && py<m && grid[px][py]==1){
                        grid[px][py] = 0;
                        q.push({px,py});
                      }
                    }
                 }
                 ans = max(ans,count);
                }
            }
         }
         return ans;
    }
};