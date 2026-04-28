class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            arr.push_back(grid[i][j]);
        }
        sort(arr.begin(),arr.end());
        
        int s=arr.size();
        if(s%2!=0){
            int mid=s/2;
            
            for(int i=0;i<=mid;i++){
                  if((arr[mid]-arr[i])%x==0)
                  ans+=(arr[mid]-arr[i])/x;
                  else return -1;
            }
            for(int i=s-1;i>=mid;i--){
                if((arr[i]-arr[mid])%x==0)
                ans+=(arr[i]-arr[mid])/x;
                else return -1;
            }
        }
        else {
            int ans1=0,ans2=0;
            int mid1=s/2-1;
            int mid2=s/2;
            // first
            for(int i=0;i<=mid1;i++){
                if((arr[mid1]-arr[i])%x==0)
                ans1+=(arr[mid1]-arr[i])/x;
                else return -1;
            }
            for(int i=s-1;i>=mid1;i--){
                if((arr[i]-arr[mid1])%x==0)
                ans1+=(arr[i]-arr[mid1])/x;
                else return -1;
            }

            // second
             for(int i=0;i<=mid2;i++){
                if((arr[mid2]-arr[i])%x==0)
                ans2+=(arr[mid2]-arr[i])/x;
                else return -1;
            }
            for(int i=s-1;i>=mid2;i--){
                if((arr[i]-arr[mid2])%x==0)
                ans2+=(arr[i]-arr[mid2])/x;
                else return -1;
            }
               ans=min(ans1,ans2);
        }
        return ans;
    }
};