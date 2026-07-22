class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        int ones =0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') ones++;
        }
        int ans = ones;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(s[i]=='1') continue;
                else {cnt++;
                    pre[i]=cnt;}
            }
            else if(i==n-1){
                if(s[i]=='1') continue;
                else {cnt++;
                     pre[i]=cnt;}
            }
            else {
                if(s[i]=='0') {
                    cnt++;
                    pre[i]=cnt;
                } 
                else{
                    bool c =0;
                    while(i<n && s[i]=='1')
                    {   c=1;
                        pre[i]= cnt;
                        i++;
                    }
                    if(c) i--;
                    cnt=0;
                }
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
                        if(i==0){
                if(s[i]=='1') continue;
                else {cnt++;
                    suf[i]=cnt;}
            }
            else if(i==n-1){
                if(s[i]=='1') continue;
                else {cnt++;
                     suf[i]=cnt;}
            }
            else {
                if(s[i]=='0') {
                    cnt++;
                    suf[i]=cnt;
                } 
                else{
                    bool c=0;
                   while(i>=0&& s[i]=='1'){
                        c=1;
                        suf[i]= cnt;
                        i--;
                   }
                   if(c) i++;
                   cnt=0;
                }
            }
        }
        for(int i=1;i<n-1;i++){
            if(s[i]=='1' && pre[i]!=0 && suf[i]!=0){
             ans = max(ans,pre[i]+suf[i]+ones);
            }
        }


        
        return ans;
    }
};