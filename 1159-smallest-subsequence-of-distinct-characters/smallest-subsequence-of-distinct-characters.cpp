class Solution {
public:
    string smallestSubsequence(string s) {
        stack<char>st;
        int n = s.size();
        vector<int>idx(26,0);
        for(int i=0;i<n;i++){
            idx[s[i]-'a'] = i;
        }
        vector<bool>present(26,0);
        for(int i=0;i<n;i++){
            if(st.empty())
            {  st.push(s[i]);
            present[s[i]-'a']=1;
            }
            else{
                if(present[s[i]-'a']) continue;
                while(!st.empty()&&s[i]<st.top()&&idx[st.top()-'a']>i)
                {
                    present[st.top()-'a']=0;
                    st.pop();
                }
                present[s[i]-'a']=1;
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};