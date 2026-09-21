class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l =0,r = 0;
        int ans =0;
        while(r<n-1){
            int maxi  = 0;
            for(int idx = l;idx<=r;idx++){
              maxi = max(maxi,idx+nums[idx]);
            }
            ans++;
            l = r+1;
            r = maxi;
        }
        return ans;
    }
};
