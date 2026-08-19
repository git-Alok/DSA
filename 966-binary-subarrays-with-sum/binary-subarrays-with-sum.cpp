class Solution {
public:
int fun(vector<int>&arr, int goal){
    if(goal<0) return 0;
    int n = arr.size();
    int l =0,r = 0;
    int sum =0;
    int count = 0;
    while(r<n){
      sum += arr[r];
      while(sum>goal){
        sum-=arr[l];
        l++;
      }
      if(sum<=goal){
        count += (r-l+1);
      }
      r++;
    }
    return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prev = fun(nums,goal-1);
        int curr=  fun(nums,goal);
      return curr-prev;
    }
};