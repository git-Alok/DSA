class Solution {
public:
bool check(int n){
    bool c=0;
    while(n){
        int rem=n%10;
        if(rem==2 || rem==5 || rem==6 || rem==9)
         c=1;
         if(rem==3 || rem==4 || rem==7)
         return false;
        n/=10;
    }
    if(c==1) return true;
    return false;
}
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            if(check(num))
            ans++;
        }
        return ans;
    }
};