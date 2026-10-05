class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                string t = "";
                t+=s[i];
                 st.push(t);
            }
            else{
                if(st.top()=="(")
                {
                    st.pop();
                    st.push("1");
                }
                else{
                    int sum = 0;
                    while(!st.empty() && st.top()!="("){
                        int num = stoi(st.top());
                        sum+=num;
                        st.pop();
                    }
                    st.pop();
                    sum = 2*sum;
                    st.push(to_string(sum));
                }
            }
        }
      int ans =0;
      while(!st.empty()){
        ans+=(stoi(st.top()));
        st.pop();
      }
        return ans;
    }
};