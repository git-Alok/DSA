class Solution {
public:
double p(double x, long long n){
      if(x==0) return 0;
        if(n==0) return 1;
        if(n==1) return x;
        if(x==1) return 1;
        if(n<0) return p(1/x,-n);
        if(n%2==0)
       return  p(x*x,n/2);
       return x*p(x*x,n/2);

}
    double myPow(double x, int n) {
       return p(x,(long long)n);

    }
};