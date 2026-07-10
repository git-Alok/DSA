class Solution {
public:
void generate(int i, int n,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
    if(i>=n) {
        ans.push_back(temp);
        return ;
    }
    temp.push_back(nums[i]);
    generate(i+1,n,nums,temp,ans);
    temp.pop_back();
    while(i<n-1 && nums[i]==nums[i+1])
    i++;
    generate(i+1,n,nums,temp,ans);
}

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n =nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        vector<vector<int>>ans;
        generate(0,n,nums,temp,ans);
        return ans;
    }
};