class Solution {
public:
int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
         int n = arr.size();
         stack<int>st;
         vector<int>left(n);
         vector<int>right(n);
         for(int i=0;i<n;i++){
            int idx = i;
            while(!st.empty()&&(arr[st.top()]>arr[i])) 
            st.pop();
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(idx);
         }
         while(!st.empty()) st.pop();

         for(int i=n-1;i>=0;i--){
              int idx = i;
            while(!st.empty()&&(arr[st.top()]>=arr[i])) 
            st.pop();
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(idx);
         }

         long long ans =0;
         for(int i=0;i<n;i++){
             long long l = i-left[i];
             long long r = right[i] - i;
          ans = (ans + (l * r % MOD) * arr[i]) % MOD;
         }
         return ans;
    }
};