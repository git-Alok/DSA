class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
             int item=nums[i];
             int sum=0;
             while(item){
                  int rem=item%10;
                  sum+=rem;
                  item/=10;
             }
             ans=min(ans,sum);
        }
        return ans;
    }
};