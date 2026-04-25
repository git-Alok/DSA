class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        typedef long long ll;
        int n=arr.size();
        vector<ll>ans(n);
        unordered_map<ll,ll>sum;
        unordered_map<ll,ll>freq;
        for(int i=0;i<n;i++){
            ll s=sum[arr[i]];
            ll f=freq[arr[i]];
            ll val=abs(s-f*i);
            ans[i]=val;
            sum[arr[i]]+=i;
            freq[arr[i]]++;
        }
        
        sum.clear();
        freq.clear();
        for(int i=n-1;i>=0;i--){
            ll s=sum[arr[i]];
            ll f=freq[arr[i]];
            ll val=abs(s-f*i);
            ans[i]+=val;
            sum[arr[i]]+=i;
            freq[arr[i]]++;
        }
        return ans;
    }
};