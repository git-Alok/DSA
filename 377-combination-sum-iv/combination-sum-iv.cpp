class Solution {
public:
int cal(int i ,vector<int>&nums,int t,vector<int>&dp){
    if(t==0) return 1;
    if(t<0) return 0;
    if(i>=nums.size()) return 0;
    if(dp[t]!=-1) return dp[t];
    int take =0;
    for(int j=0;j<nums.size();j++){
         take += cal(j,nums,t-nums[j],dp);
    }
    return dp[t] = take;
}
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1,-1);
        return cal(0,nums,target,dp);
    }
};