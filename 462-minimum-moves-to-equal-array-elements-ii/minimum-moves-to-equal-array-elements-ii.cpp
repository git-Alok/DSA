class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int ans =0;
        for(int i=0;i<n/2;i++){
            ans+= abs(nums[i]-nums[n/2]);
            ans+= abs(nums[n-1-i]-nums[n/2]);
        }
        return ans;
    }
};