class Solution {
public:
void permutation(vector<int>&nums, vector<bool>&visit, int n , vector<int>&temp, vector<vector<int>>&ans){
    if(temp.size()==n){
        ans.push_back(temp);
        return;
    }
    for(int i =0 ;i<n;i++){
        if(visit[i]==0){
            visit[i]=1;
            temp.push_back(nums[i]);
            permutation(nums, visit, n,temp,ans);
            visit[i]=0;
            temp.pop_back();
        }
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>visit(n,0);
        vector<vector<int>>ans;
        vector<int>temp;
        permutation(nums, visit, n,temp,ans);
        return ans;
    }
};