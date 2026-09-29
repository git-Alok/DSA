class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return 0;
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        for(int i=1;i<n;i++){
         if(arr[i]>arr[i-1])
         pre[i]= 1+pre[i-1];
        }
        for(int i=n-2;i>=0;i--){
          if(arr[i]>arr[i+1])
          suf[i] = 1+suf[i+1];
        }
        int count =0;
        for(int i=0;i<n;i++){
          if(pre[i]!=0 && suf[i]!=0)
          count = max(count,pre[i]+suf[i]+1);
        }
        return count;
    }
};