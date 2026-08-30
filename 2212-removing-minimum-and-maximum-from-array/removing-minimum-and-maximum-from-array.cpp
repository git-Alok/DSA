class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=1) return 1;
        int min_idx =-1;
        int max_idx = -1;
        int maxi = INT_MIN;
        int mini= INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(maxi<nums[i])
            {
                maxi = nums[i];
                max_idx = i;
            }
            if(mini>nums[i]){
                mini = nums[i];
                min_idx = i;
            }
        }
        cout<<min_idx<<" "<<max_idx;
        int fir = max(max_idx+1,min_idx+1);
        int sec = max(n-min_idx , n-max_idx);
        int thr = (n-min_idx) + (max_idx+1);
        int frth = (n-max_idx)+(min_idx+1);
        return min({fir,sec,thr,frth});
    }
};