class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int countk=0;
        unordered_map<int,int>mp1;
        while(j<n&& i<n){
          mp1[nums[j]]++;
          if(mp1.size()<=k){
          countk+=(j-i+1);
          j++;
          }
          else {
            while(mp1.size()>k)
           {  mp1[nums[i]]--;
           if(mp1[nums[i]]==0)
           mp1.erase(nums[i]);
           i++;
           }
           countk+=(j-i+1);
           j++;
          }   
        }
     

    //  for k-1;
    k--;
        i=0,j=0;
        int countk_1=0;
        unordered_map<int,int>mp2;
        while(j<n&& i<n){
          mp2[nums[j]]++;
          if(mp2.size()<=k){
          countk_1+=(j-i+1);
          j++;
          }
          else {
            while(mp2.size()>k)
           {  mp2[nums[i]]--;
           if(mp2[nums[i]]==0)
           mp2.erase(nums[i]);
           i++;
           }
           countk_1+=(j-i+1);
           j++;
          }   
        }
     return countk - countk_1;
    }
};