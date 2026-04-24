class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
       vector<long long>ans(n);
       unordered_map<long long ,long long>sum;
       unordered_map<long long,long long>freq;
    //    left
    for(int i=0;i<n;i++){
        long long s=sum[nums[i]];
        long long f=freq[nums[i]];
        f=f*i;
        long long val=abs(f-s);
        ans[i]=val;
        sum[nums[i]]+=i;
        freq[nums[i]]++;
    }
    sum.clear();
    freq.clear();

    //  right
     for(int i=n-1;i>=0;i--){
        long long s=sum[nums[i]];
        long long f=freq[nums[i]];
        f=f*i;
        long long val=abs(f-s);
        ans[i]+=val;
        sum[nums[i]]+=i;
        freq[nums[i]]++;
    }
       
        return ans;
    }

};
