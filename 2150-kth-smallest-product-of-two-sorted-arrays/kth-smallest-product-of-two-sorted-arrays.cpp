class Solution {
public:

long long findcountpair(vector<int>&nums1, vector<int>&nums2, long long midprod){
    int n = nums2.size();
     long long countpair=0;
    for(int i=0;i<nums1.size();i++){
         if(nums1[i]>=0){
            int l =0,r = n-1;
            int m = -1;
            while(l<=r){
                int mid = l+(r-l)/2;
                long long pro = 1LL * nums1[i]*nums2[mid];
                if(pro<=midprod){
                     m = mid;
                     l = mid+1;
                }
                else {
                    r = mid-1;
                }
            }
            countpair+=(m+1);
         }
         else {
            int l = 0, r = n-1;
            long long m = n;
            while(l<=r){
                int mid = l+(r-l)/2;
                long long pro = 1LL * nums1[i]*nums2[mid];
                if(pro<=midprod){
                    m = mid;
                    r  = mid-1;
                }
                else {
                    l = mid+1;
                }
            }
            countpair+=(n-m);
         }
    }
    return countpair;
}

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long l = -1e10;
        long long r = 1e10;
        long long result = 0;
        while(l<=r){
            long long midprod = l+(r-l)/2;
            long long countpair = findcountpair(nums1,nums2,midprod);

            if(countpair>=k){
                result = midprod;
                r = midprod-1;
            }
            else l = midprod+1;
        }
        return result;

    }
};