class Solution {
public:
void combo(int i,int n ,int k,vector<int>&temp,vector<vector<int>>&ans){
    if(i>n){
        if(temp.size()==k)
            ans.push_back(temp);
        return ;
    }
    if(temp.size()==k){
        ans.push_back(temp);
        return ;
    }
     temp.push_back(i);
    combo(i+1,n,k,temp,ans);
     temp.pop_back();
    combo(i+1,n,k,temp,ans);
}
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int>>ans;
        combo(1,n,k,temp,ans);
        return ans;
    }
};