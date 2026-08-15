class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
      int n = nums.size();
      int x_or = 0;
      bool non_zero =0;
      for(int i=0;i<n;i++){
        x_or = x_or^nums[i];
        if(nums[i]>0) non_zero = 1;
      }  
      if(x_or !=0) return n;
      if(non_zero==0) return 0;
      return n-1;
    }
};