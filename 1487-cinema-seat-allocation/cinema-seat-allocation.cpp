class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_map<int,bool>>mp;
        int m = reservedSeats.size();

        for(int i=0;i<reservedSeats.size();i++){
            int r = reservedSeats[i][0];
            int s = reservedSeats[i][1];
            mp[r][s]=1;
        }
        int ans =0;
      for(auto it = mp.begin(); it != mp.end(); it++){
         unordered_map<int,bool>dub = it->second;
         int count = 0;
         if(dub[2]==0 && dub[3]==0 && dub[4]==0 && dub[5]==0){
            dub[2]=1;
            dub[3]=1;
            dub[4]=1;
            dub[5]=1;
             count++;
         }
         if(dub[4]==0 && dub[5]==0 && dub[6]==0 && dub[7]==0){
            dub[4]=1;
            dub[5]=1;
            dub[6]=1;
            dub[7]=1;
             count++;
         }
         if(dub[6]==0 && dub[7]==0 && dub[8]==0 && dub[9]==0){
            dub[6]=1;
            dub[7]=1;
            dub[8]=1;
            dub[9]=1;
          count++;
         }
         ans +=count;
      }
      int s = 2*(n-mp.size());
        return ans+s;
    }
};