class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int i=0,j=n-1;
        int k=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==nums[k]){
                ans=min(ans,nums[k]);
                while(k<=mid && nums[mid]==nums[k])
                {   
                    k++;
                }
                i=k;
            }
           else if(nums[mid]>nums[k]){
            ans=min(ans,nums[k]);
                i=mid+1;
            }
            else {
                ans=nums[mid];
                j=mid-1;
            }
        }
        return ans;
    }
};