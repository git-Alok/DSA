class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        sort(nums.begin(),nums.end());
        set<int>st;
        st.insert(nums[0]);
        for(int i=1;i<n;i++){
            int val = nums[i];
            if(st.find(nums[i])!=st.end()){
                val = nums[i-1]+1;
                ans += (val-nums[i]);
                nums[i] = val;
            }
            st.insert(val);
         }
         return ans;
    }
};