class Solution {
public:
int digit_prod(int n){
    int pro = 1;
    while(n){
        int rem = n%10;
        pro = pro*rem;
        n=n/10;
    }
    return pro;
}
    int smallestNumber(int n, int t) {
         while(n){
            if(digit_prod(n)%t==0) return n;
            n++;
         }
         return -1;
    }
};