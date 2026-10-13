class Solution {
public:
int row[4] = {1,-1,0,0};
int col[4] = {0,0,1,-1};
void bfs(int i,int j,vector<vector<char>>&board,char val){
    queue<pair<int,int>>q;
    int n = board.size();
    int m = board[0].size();
    q.push({i,j});
    board[i][j] = val;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int u = x+row[k];
            int v = y+col[k];
            if(u>=0 && u<n && v>=0 && v<m && board[u][v]=='O')
            {
                board[u][v] = val;
                q.push({u,v});
            }
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
            bfs(i,0,board,'L');
            if(board[i][m-1]=='O')
            bfs(i,m-1,board,'L');
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O')
            bfs(0,j,board,'L');
            if(board[n-1][j]=='O')
            bfs(n-1,j,board,'L');
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O')
                bfs(i,j,board,'X');
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='L')
                board[i][j]='O';
            }
        }
        return ;
    }
};