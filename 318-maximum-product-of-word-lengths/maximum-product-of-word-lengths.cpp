class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n =words.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>freq1(26,0);
            for(int x =0;x<words[i].size();x++)
            freq1[words[i][x]-'a']++;

        for(int j=i+1;j<n;j++){
            vector<int>freq2(26,0);
            for(int x =0;x<words[j].size();x++)
            freq2[words[j][x]-'a']++;

            // comparision
            bool c =0;
            for(int k=0;k<26;k++){
                if(freq1[k]&&freq2[k])
                 c=1;
            }
            int u = words[i].size();
            int v = words[j].size();
            
            if(c==0){
                ans = max(ans,u*v);
            }
            
        }
        }
        return ans;
    }
};