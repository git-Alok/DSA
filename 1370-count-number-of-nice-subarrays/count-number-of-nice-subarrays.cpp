class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>idx;
        for(int i=0;i<n;i++){
            if(nums[i]%2 !=0) idx.push_back(i);
        }
        if(idx.size()<k) return 0;
        int i=0, j = k-1;
        int ans =0;
        for(j = k-1;j<idx.size();j++){
            int x = i==0 ? -1 : idx[i-1];
            int y = j== idx.size()-1 ? n : idx[j+1];
            ans = ans + (idx[i]-x)*(y-idx[j]);
            i++;
        }
        return ans;
    }
};