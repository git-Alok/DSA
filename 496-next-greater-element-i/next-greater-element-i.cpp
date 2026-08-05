class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
      unsigned int n1 = nums1.size();
      unsigned int n2 = nums2.size();
      for(int i=0;i<n2;i++){
        mp[nums2[i]]=i;
      }
      reverse(nums2.begin(),nums2.end());
      stack<int>st;
      for(int i=0;i<n2;i++){
        int val  = nums2[i];
         while(!st.empty() && st.top()<nums2[i])
         st.pop();
         if(st.empty()) nums2[i] = -1;
         else nums2[i]=st.top();
         st.push(val);
      }
      reverse(nums2.begin(),nums2.end());
      for(int i=0;i<n1;i++){
        int val = nums1[i];
        int idx = mp[val];
        nums1[i] = nums2[idx];
      }
       return nums1;
    }
};