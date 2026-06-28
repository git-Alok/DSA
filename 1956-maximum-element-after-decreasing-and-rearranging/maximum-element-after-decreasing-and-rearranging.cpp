class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr.size()==1) return 1;
        int n=arr.size();
        int ans = INT_MIN;
        arr[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]!=arr[i-1])
            arr[i]=1+arr[i-1];
            ans = max(ans,arr[i]);
        }
        return ans;
    }
};