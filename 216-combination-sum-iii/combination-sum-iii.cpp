class Solution {
public:
vector<vector<int>>ans;
void cal(int k,int count, int target, vector<int>&temp){
    if(0==target && k==0){
        ans.push_back(temp);
        return ;
    }
    if(k<=0 || target<0 || count>9) return ;
    temp.push_back(count);
    cal(k-1,count+1,target-count,temp);
    temp.pop_back();
    cal(k,count+1,target,temp);

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        cal(k,1,n,temp);
        return ans;
    }
};