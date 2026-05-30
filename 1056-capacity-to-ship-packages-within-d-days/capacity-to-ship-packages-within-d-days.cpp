class Solution {
public:
bool check(vector<int>& weights, int days,int capacity){
    int d=0;
    int sum=0;
      int n=weights.size();
    for(int i=0;i<n;i++){
        if(weights[i]>capacity) return false;
       if(sum+weights[i]<=capacity)
       sum+=weights[i];
       else 
       {
        sum=weights[i];
        d++;
       }
       if(d>days) return false;
    }
    if(sum<=capacity){
         d++;
    }
    return d<=days;

}
    int shipWithinDays(vector<int>& weights, int days) {
        long long sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum+= weights[i];
        }
        int ans=sum;
        int i=1,j=sum;
        while(i<=j){
            int mid = i+(j-i)/2;
            bool possible = check(weights,days,mid);
            if(possible==1){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;

    }
};