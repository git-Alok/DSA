class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool>is_prime(n,1);
        for(int i=2;i*i<=n;i++){
            if(is_prime[i]==0) continue;
            else {
                for(int j=2*i;j<n;j+=i)
                is_prime[j]=0; 
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(is_prime[i]) ans++;
        }
        return ans;
    }
};