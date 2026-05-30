class Solution {
public:
bool check(vector<int>& nums, int k, long long mid){
    int count=0;
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid) return false;
        if(sum+nums[i]<=mid)
        sum+=nums[i];
        else {
            count++;
            sum=nums[i];
        }
        if(count>k) return false;
    }
    if(sum<=mid) count++;
    return count<=k;

}
    int splitArray(vector<int>& nums, int k) {
       int n=nums.size();
       long long sum=0;
       for(int i=0;i<n;i++)
       {
        sum+=nums[i];
       }
       int i= *max_element(nums.begin(),nums.end());
       int j=sum;
       int ans=sum;
       while(i<=j){
        long long mid=i+(j-i)/2;
        bool possible=check(nums,k,mid);
        if(possible==1){
            ans=mid;
            j=mid-1;
        }
        else 
        i=mid+1;
       }
       return ans;
    }
};