class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int t=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) t++;
                if((j-i+1)/2<t) count++;
            }
        }
        return count;
    }
};