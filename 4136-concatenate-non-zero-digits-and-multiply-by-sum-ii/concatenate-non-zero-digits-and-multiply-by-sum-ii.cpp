class Solution {
public:
int mod  = 1e9+7;
long long power(long long a, long long b, long long mod) {
    long long ans = 1;

    while (b > 0) {
        if (b & 1)
            ans = (ans * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }

    return ans;
}
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long>sum(n,0);
        vector<long long>subarray(n,0);
        vector<long long>count(n,0);
        vector<int>ans;
        sum[0] = s[0]-'0';
        subarray[0] = s[0]-'0';
        if(s[0]!='0')
        count[0] = 1;
        for(int i=1;i<n;i++){
              sum[i] = (sum[i-1]+(s[i]-'0'))%mod;
              if(s[i]!='0'){
                subarray[i] = (subarray[i-1]*10 + (s[i]-'0'))%mod;
                count[i] = 1+count[i-1];
              }
              else {
                subarray[i] = subarray[i-1];
                count[i] = count[i-1];
              }
        }


        int m = queries.size();
        for(int i=0;i<m;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            if(l==0){
              ans.push_back((int)((subarray[r]*sum[r])%mod));
            }
            else {
                 long long d = (count[r]-count[l-1]);
                long long x = power(10,d,mod);
                long long val = (subarray[l-1]*x)%mod;
                val = (subarray[r]-val+mod)%mod;
                ans.push_back((int)val*(sum[r]-sum[l-1])%mod);
            }
        }
        return ans;
    }
};