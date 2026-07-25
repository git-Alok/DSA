class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
           int n = nums.size();
        vector<bool>visit1(2049);
        vector<bool>visit2(2049);
        visit1[0]=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int val = nums[i]^nums[j];
                visit1[val] =true;
            }
        }

        int count=0;
      for(int i=0;i<2049;i++){
        if(!visit1[i]) continue;
        for(auto num : nums){
            if(!visit2[num^i]) count++;
            visit2[num^i] =1;
        }
      }
        return count;
    }
};