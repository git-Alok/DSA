class Solution {
public:
    int trap(vector<int>& height) {
        int  n = height.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&st.top()<=height[i]) 
            st.pop();
            if(st.empty()) 
            {
              left[i] = -1;
              st.push(height[i]);
            }
            else left[i] = st.top();
        }
        while(!st.empty()) st.pop();

         for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=height[i]) 
            st.pop();
            if(st.empty()) 
            {
              right[i] = -1;
              st.push(height[i]);
            }
            else right[i] = st.top();
        }
        // for(auto num : left) cout<<num<<" ";
        // cout<<endl;
        // for(auto num : right) cout<<num<<" ";
        
        int ans =0;
        for(int i=0;i<n;i++){
            if(left[i]==-1 || right[i]==-1) continue;
            int w = min(left[i],right[i]);
            ans = ans+(w-height[i]);
        }
        return ans;

    }
};