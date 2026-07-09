class Solution {
public:
void generate(int i,int n,vector<int>&arr,int target,vector<int>&temp,vector<vector<int>>&ans){
    if(target==0) {
        ans.push_back(temp);
        return ;
    }
    if(i==n || target<0) return;
    temp.push_back(arr[i]);
    generate(i,n,arr,target-arr[i],temp,ans);
    temp.pop_back();
    generate(i+1,n,arr,target,temp,ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        vector<vector<int>>ans;

        generate(0,n,candidates,target,temp,ans);
        return ans;
    }
};