class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>nsl(n);
        vector<int>nsr(n);
        vector<int>ngl(n);
        vector<int>ngr(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&(nums[st.top()]<nums[i]))
            st.pop();
            if(st.empty()) ngl[i] = -1;
            else ngl[i] = st.top();
            st.push(i);
        }
        
        while(!st.empty()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&(nums[st.top()]<=nums[i]))
            st.pop();
            if(st.empty()) ngr[i] = n;
            else ngr[i] = st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty()&&(nums[st.top()]>nums[i]))
            st.pop();
            if(st.empty()) nsl[i] = -1;
            else nsl[i] = st.top();
            st.push(i);
        }
         while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&(nums[st.top()]>=nums[i]))
            st.pop();
            if(st.empty()) nsr[i] = n;
            else nsr[i] = st.top();
            st.push(i);
        }

       while(!st.empty()) st.pop();
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long maxi =(i-ngl[i])*(ngr[i]-i); 
            long long mini = (i-nsl[i])*(nsr[i]-i);
            long long fir = maxi*nums[i];
            long long sec = mini*nums[i];
            ans = ans+(fir-sec);
        }
        return ans;
    }
};