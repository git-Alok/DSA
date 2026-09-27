class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp;
        vector<int>ans(n);
        temp.push_back(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            int s = 0,e = temp.size()-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(temp[mid]<nums[i])
                s = mid+1;
                else e = mid-1;
            }
            ans[i] = s;
            temp.insert(temp.begin()+s,nums[i]);
        }
        return ans;
    }
};