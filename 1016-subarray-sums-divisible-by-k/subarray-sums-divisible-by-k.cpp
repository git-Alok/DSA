class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        map<int,int>mp;
        vector<int>pre(n,0);
        pre[0] = ((nums[0]%k)+k)%k;
        for(int i=1;i<n;i++){
           pre[i] = (((nums[i]+pre[i-1])%k)+k)%k;
        }
        for(int i=0;i<n;i++){
         if(pre[i]==0)
         ans++;
         ans = ans+mp[pre[i]];
         mp[pre[i]]++;
        }
        return ans;
    }
};