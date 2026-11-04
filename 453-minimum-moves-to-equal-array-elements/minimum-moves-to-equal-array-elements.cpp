class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int mini = *min_element(nums.begin(),nums.end());
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]-mini);
        }
        return ans;

        // 2nd approach
        // int n = nums.size();
        // int sum = 0;
        // for(auto num : nums)
        // sum += num;
        // int mini = *min_element(nums.begin(),nums.end());
        // return sum - n*(mini);
    }
};