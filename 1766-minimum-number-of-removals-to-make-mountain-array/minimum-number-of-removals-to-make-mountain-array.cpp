class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        for(int i=1;i<n;i++){
           for(int j=i-1;j>=0;j--){
               if(nums[j]<nums[i]){
                pre[i] = max(pre[i],1+pre[j]); 
               }
           }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[i])
                suf[i] = max(suf[i],1+suf[j]);
            }
        }
       int ans = INT_MAX;
        for(int i=1;i<n-1;i++){
            if(pre[i]==0 || suf[i] ==0) continue;
            int val = pre[i]+suf[i]+1;
            ans = min(ans,n-val);
        }
        for(auto k : pre)
        cout<<k<<" ";
        cout<<endl;
        for(auto k : suf)
        cout<<k<<" ";
        return ans;
    }
};