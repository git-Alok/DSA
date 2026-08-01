class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n==k) return "0";
        stack<char>st;
        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(num[i]);
            else{
                while(!st.empty() && k>0 && st.top()>num[i])
                {
                    k--;
                    st.pop();
                }
                st.push(num[i]);
            }
        }
        while(!st.empty()&&k--){
            st.pop();
        }
        stack<char>dub;
        while(!st.empty()){
            dub.push(st.top());
            st.pop();
        }
        while(!dub.empty()&& dub.top()=='0'){
          dub.pop();
        }
        if(dub.empty()) return "0";
        string ans="";
        while(!dub.empty()){
            ans+=dub.top();
            dub.pop();
        }
        return ans;
    }
};