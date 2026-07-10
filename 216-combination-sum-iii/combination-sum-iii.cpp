class Solution {
public:
  void generate(int i,int n ,int k,vector<int>&temp,vector<vector<int>>&ans){
     if(n==0 && temp.size()==k) {
        ans.push_back(temp);
        return ;
     }
     if(n<0 || temp.size()>k || i>9)
     return ;
    
    temp.push_back(i);
    generate(i+1,n-i,k,temp,ans);
    temp.pop_back();
    generate(i+1,n,k,temp,ans);
  }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        vector<vector<int>>ans;
        generate(1,n,k,temp,ans);
        return ans;
    }
};