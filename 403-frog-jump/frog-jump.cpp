class Solution {
public:
int t[2001][2001] ;
unordered_map<int,int>mp;
bool check(vector<int>&stones,int csi, int prev_jump){
    if(csi == stones.size()-1) return true;
    if(t[prev_jump][csi]!=-1) return t[prev_jump][csi];
    bool result = false;
    for(int jump = prev_jump-1;jump<=prev_jump+1;jump++){
        int nxt_jump = stones[csi] + jump;
        if(jump>0){
            if(mp.find(nxt_jump)!=mp.end()){
                result = result || check(stones,mp[nxt_jump],jump);
            }
        }
    }
    return t[prev_jump][csi] = result;
}
    bool canCross(vector<int>& stones) {
      int n = stones.size();
      for(int i=0;i<n;i++)
      mp[stones[i]] = i;
      memset(t,-1,sizeof(t));
      return check(stones,mp[0],0);
    }
};