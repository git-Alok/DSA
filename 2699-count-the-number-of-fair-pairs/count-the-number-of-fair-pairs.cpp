class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
         int n = nums.size();
         long long ans1 = 0;
         long long ans2 =0;
        sort(nums.begin(),nums.end());
        int i=0, j=n-1;
        while(i<j){
           if(nums[i]+nums[j]<=upper)
             {
                ans1 +=(j-i);
                i++;
             }
             else j--;
        }
        i=0,j=n-1;
        while(i<j){
            if(nums[i]+nums[j]<lower){
                ans2 += (j-i);
                i++;
            }
            else j--;
        }
        return ans1-ans2;
    }
};