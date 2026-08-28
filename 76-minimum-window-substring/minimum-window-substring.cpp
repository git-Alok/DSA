class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int n = s.size();
        int m = t.size();
        for(int i=0;i<m;i++)
        mp[t[i]]++;
        int count = m;
        int i=0,j=0;
        int l=0,r=0;
        int k = INT_MAX;
        string ans ="";
        bool c=1;
        while(i<n&& j<n){
             mp[s[j]]--;
             if(mp[s[j]]>=0)
             count--;
             while(count==0)
             {     int temp = j-i+1;
                    if(k>temp)
                    {
                        k = temp;
                        l=i;
                        r=j;
                    }
                mp[s[i]]++;
                if(mp[s[i]]>0)
                count++;
                i++;
             }
             j++;
        }
        if(k==INT_MAX) return "";
        ans = s.substr(l,r-l+1);
        return ans;
    }
};