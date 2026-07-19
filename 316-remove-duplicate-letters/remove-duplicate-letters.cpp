class Solution {
public:
    string removeDuplicateLetters(string s) {
          int n = s.size();
          stack<char>st;
          vector<int>idx(26);
          for(int i=0;i<n;i++){
                idx[s[i]-'a']=i;
          }
         vector<bool>visit(26);
         for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
                visit[s[i]-'a']=1;
            }
            else{
                if(visit[s[i]-'a']) continue;
                while(!st.empty() && s[i]<st.top() && i<idx[st.top()-'a']){
                    visit[st.top()-'a']=0;
                     st.pop();
                }
                st.push(s[i]);
                visit[s[i]-'a']=1;
            }
         }
         string ans ="";
         while(!st.empty()){
            ans+=(st.top());
            st.pop();
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};