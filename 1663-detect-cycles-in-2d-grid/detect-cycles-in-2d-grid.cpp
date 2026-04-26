class Solution {
public:
int n,m;
bool bfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&visit){
    queue<pair<pair<int,int>,pair<int,int>>>q;
    q.push({{-1,-1},{i,j}});
   
    while(!q.empty()){
       int x=q.front().second.first;
       int y=q.front().second.second;
       int p1=q.front().first.first;
       int p2=q.front().first.second;
       if(visit[x][y]) return 1;
       visit[x][y]=1;
       q.pop();
       if(x+1<n && grid[x+1][y]==grid[x][y] && (x+1!=p1 || y!=p2)){
          q.push({{x,y},{x+1,y}});
       }
       if(x-1>=0 && grid[x-1][y]==grid[x][y] && (x-1!=p1 || y!=p2)){
          q.push({{x,y},{x-1,y}});
       }

       if(y+1<m && grid[x][y+1]==grid[x][y] && (x!=p1 || y+1!=p2)){
         q.push({{x,y},{x,y+1}});
    }

    if(y-1>=0 && grid[x][y-1]==grid[x][y] && (x!=p1 || y-1!=p2)){
       q.push({{x,y},{x,y-1}});
    }

}
    return false;
}

    bool containsCycle(vector<vector<char>>& grid) {
         n=grid.size();
         m=grid[0].size();
        vector<vector<bool>>visit(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visit[i][j]==0){
                    bool c=bfs(i,j,grid,visit);
                    if(c) return true;
                }
            }
        }
        return false;
    }
};