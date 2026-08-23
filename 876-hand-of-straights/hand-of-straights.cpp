class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        sort(hand.begin(),hand.end());
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(mp.size()>0){
            int count =0;
            int k = mp.begin()->first - 1;
            for(auto it = mp.begin();it!=mp.end();it++){
               if(k+1 != it->first) return false;
               mp[k+1]--;
               if(mp[k+1]==0) mp.erase(k+1);
               k++;
               count++;
               if(count==groupSize) break;
            }
            if(count<groupSize) return false;
        }
    return true;

    }
};