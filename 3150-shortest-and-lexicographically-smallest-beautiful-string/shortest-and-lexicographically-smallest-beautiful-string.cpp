class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i=0,j=0;
        string ans = "";
        int k_dub=0;
        while(i<n && j<n){
           if(s[j]=='1')
           { k_dub ++;
           }
         while(k_dub>k){
            if(s[i]=='1')
               k_dub--;
            i++;
         }
         while(i<n && s[i]!='1')
         i++;
         if(k_dub==k){
            if(ans.size()==0) ans = s.substr(i,j-i+1);
            if(ans.size()>j-i+1)
            ans = s.substr(i,j-i+1);
            else if(ans.size()==(j-i+1) && ans>s.substr(i,j-i+1))
            ans = s.substr(i,j-i+1);
         }
         j++;    
        }
        return ans;
    }
};