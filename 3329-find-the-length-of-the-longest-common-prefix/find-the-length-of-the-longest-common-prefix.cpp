class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,bool>mp;
        int n1=arr1.size();
        for(int i=0;i<n1;i++){
             string temp=to_string(arr1[i]);
             string s="";
             for(int j=0;j<temp.size();j++){
                   s+=temp[j];
                   mp[s]=1;
             }
        }
        int ans=0;
       int n2=arr2.size();
       for(int i=0;i<n2;i++){
          string temp=to_string(arr2[i]);
          string s="";
          for(int j=0;j<temp.size();j++){
             s+=temp[j];
             if(mp[s]==1)
                ans=max(ans,j+1);
             else break;
       }
       }
       return ans;

    }
};