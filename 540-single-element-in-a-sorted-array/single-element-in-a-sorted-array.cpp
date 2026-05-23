class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int i=0,j=n-1;
        int idx=0;
        while(i<=j){
             int mid=i+(j-i)/2;
                if(mid>0&&mid<n-1 && nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
                {
                   idx=mid;
                   break;
                } 
                else if(mid==0 && nums[mid]!=nums[mid+1]){
                    idx=mid;
                    break;
                }
                else if(mid==n-1 && nums[mid]!=nums[mid-1])
                {
                    idx=mid;
                    break;
                }
                else if(mid>0 && nums[mid]==nums[mid-1])
                {
                    if((mid-1)%2!=0)
                    j=mid-2;
                    else 
                    i=mid+1;
                }
                else if(mid<n-1 && nums[mid]==nums[mid+1]){
                    if(mid%2!=0)
                    j=mid-1;
                    else 
                    i=mid+2;
                }
                else break;

        }
        return nums[idx];
    }
};