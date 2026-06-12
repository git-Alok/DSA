class Solution {
public:
int find_max(vector<int>&arr){
    int m=INT_MIN;
  for(int i=0;i<26;i++){
      m=max(m,arr[i]);
  }
  return m;
}

int find_min(vector<int>&arr){
      int m=INT_MAX;
  for(int i=0;i<26;i++){
      if(arr[i]!=0)
      m= min(m,arr[i]);
  }
  return m;
}
    int beautySum(string s) {
        int n=s.size();
       int ans =0;
        for(int i=0;i<n;i++){
             vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int maxi = find_max(freq);
                int mini = find_min(freq);
                ans+=(maxi-mini);
            }
        }
        return ans;
    }
};