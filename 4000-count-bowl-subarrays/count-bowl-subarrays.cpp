class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int>st1;
        stack<int>st2;
        vector<int>left(n);
        vector<int>right(n);
        for(int i=0;i<n;i++){
            int val = nums[i];
            while(!st1.empty()&&(st1.top()<=nums[i])) st1.pop();
            if(st1.empty()) left[i] = -1;
            else left[i] = st1.top();
            st1.push(val);
        }

        for(int i=n-1;i>=0;i--){
        int val = nums[i];
        while(!st2.empty()&&(st2.top()<=nums[i])) st2.pop();
        if(st2.empty()) right[i]=-1;
        else right[i]= st2.top();
        st2.push(val);
        } 
        long long ans = 0;
        for(int i=0;i<n;i++){
            long long mini = min(left[i],right[i]);
            if(mini>nums[i]) ans++;
        }
        return ans;
    }
};