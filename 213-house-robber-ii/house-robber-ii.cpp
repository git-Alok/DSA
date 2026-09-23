class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max({nums[0],nums[1],nums[2]});
        int f1 = nums[n-1];
        int s1 = max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>0;i--){
            int t= max(s1,nums[i]+f1);
            f1  = s1;
            s1 = t;
        }
        int f2 = nums[n-2];
        int s2 = max(nums[n-2],nums[n-3]);
        for(int i=n-4;i>=0;i--){
            int t = max(s2,nums[i]+f2);
            f2 = s2;
            s2 = t;
        }
        return max(s2,s1);
    }
};