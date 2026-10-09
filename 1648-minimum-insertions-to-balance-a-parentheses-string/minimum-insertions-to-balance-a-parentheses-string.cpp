class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int ans = 0;
        stack<char>st;
        int i=0;
        while(i<n){
            if(s[i]=='('){
               st.push('(');
               i++;
            } 
            else if(st.empty()){
                ans++;
                if(i+1<n && s[i+1]!=')' || i+1>=n){
                     ans++;
                     i++;
                     continue;
                }
                i+=2;
            }
            else{
                st.pop();
                if(i+1<n && s[i+1]!=')' || i+1>=n)
                {
                    ans++;
                    i++;
                    continue;
                }
                i+=2;
            }
        }
        if(!st.empty()){
            ans+=(2*st.size());
        }
        return ans;
    }
};