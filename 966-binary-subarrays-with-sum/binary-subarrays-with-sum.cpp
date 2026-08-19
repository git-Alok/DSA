class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
       int n = nums.size();
       vector<int>idx;
        if(goal>0){
        for(int i=0;i<n;i++){
            if(nums[i]==1){
               idx.push_back(i);
            }
        }
        int i=0,j=goal-1;
        int ans = 0;
        for(j=goal-1;j<idx.size();j++){
            int x = i==0 ? -1 : idx[i-1];
            int y = j==idx.size()-1 ? n : idx[j+1];
            ans = ans + (idx[i]-x)*(y-idx[j]);
            i++;
        }
         return ans;
}
   idx.push_back(-1);
    for(int i=0;i<n;i++){
            if(nums[i]==1){
               idx.push_back(i);
         }
    }
    idx.push_back(n);
        int ans = 0;
        for(int j=1;j<idx.size();j++){
           int k = (idx[j]-idx[j-1]-1);
           ans = ans + (k*(k+1))/2;
        }
        return ans;
    }
};