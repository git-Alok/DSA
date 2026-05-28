class Solution {
public:
bool check(vector<int>& nums, int thr,int m){
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n;i++){
        if(nums[i]<=m){
           sum++;
        }
       
        else {
            sum+=ceil((nums[i]*1.0)/m);
        }
        if(sum>thr) return false;
    }
    return true;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1,j=*max_element(nums.begin(),nums.end());
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            bool possible=check(nums,threshold,mid);
            if(possible==1)
            { ans=mid;
             j=mid-1;
            }
            else 
            i=mid+1;
        }
        return ans;
    }
};