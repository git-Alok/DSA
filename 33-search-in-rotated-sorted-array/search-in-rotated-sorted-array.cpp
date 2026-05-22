class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1;
        int ans=-1;
        while(i<=j){
         int mid=i+(j-i)/2;
         if(nums[mid]==target){
            ans=mid;
            break;
         }
         else if(nums[0]<=nums[mid])
         {
            if(target>=nums[0] && target<nums[mid])
            j=mid-1;
            else i=mid+1;
         }
         else {
            if(target>=nums[0])
            j=mid-1;
            else {
                if(target<nums[mid])
                j=mid-1;
                else 
                i=mid+1;
            }
         }   
        }
        return ans;
    }
};