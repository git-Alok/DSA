class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==1) return 1;
        vector<int>arr(n,1);
        if(ratings[0]>ratings[1]) arr[0] = 1 + arr[1];
        for(int i=1;i<n-1;i++){
            if(ratings[i]>ratings[i+1] && ratings[i]>ratings[i-1])
            arr[i] = 1+ max(arr[i-1],arr[i+1]);
            else if(ratings[i]>ratings[i-1]) arr[i] = arr[i-1]+1;
            else if(ratings[i]>ratings[i+1]) arr[i] = 1+arr[i+1];
        }
        if(ratings[n-1]>ratings[n-2]) 
        arr[n-1]= 1+arr[n-2];

        for(int i=n-2;i>0;i--){
            if(ratings[i]>ratings[i+1] && arr[i]<=arr[i+1])
            arr[i] = max(arr[i],1+arr[i+1]);
            if(ratings[i]>ratings[i-1] && arr[i]<=arr[i-1]) 
            arr[i] = max(arr[i],1+arr[i-1]+1);
        }
        if(ratings[0]>ratings[1] && arr[0]<=arr[1]) 
         arr[0] = 1+arr[1];
        int ans =0;
        for(int i=0;i<n;i++)
        ans+=arr[i];
        return ans;
    }
};