class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        map<char,int>mp;
        int i=0;
        int maxi  = 0;
        for(int j=0;j<n;j++){
            if(!mp[s[j]]){
                mp[s[j]]++;
                maxi = max(maxi,j-i+1);
            }
            else {
                while(i<n&&mp[s[j]])
                {
                    mp[s[i]]--;
                    i++;
                }
                mp[s[j]]++;
            }
        }
        return maxi;
         
    }
};