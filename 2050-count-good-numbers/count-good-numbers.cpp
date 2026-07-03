class Solution {
public:
int mod  = 1e9+7;
int power(long long a, long long b){
    if(b==0) return 1;
    long long half = power(a, b/2);
    long long res = (half * half)%mod;
    if(b%2==1)
    res = (a*res)%mod;
    return res;
}
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        return ((long long)power(5,even) * (long long)power(4,odd))%mod;
        
    }
};