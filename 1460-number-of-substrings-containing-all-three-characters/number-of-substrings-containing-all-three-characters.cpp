class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>freq(3,0);
        int n=s.size();
        int count=0;
        int i=0,j=0;
        while(j<n){
            freq[s[j]-'a']++;
            if(freq[0]>0 && freq[1]>0 && freq[2]>0){
                count+=(n-j);
                freq[s[i]-'a']--;
                i++;
                while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                    count+=(n-j);
                     freq[s[i]-'a']--;
                    i++;
                }
            }
          j++;
        }
        return count;
    }
};