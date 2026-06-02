class Solution {
public:
double fun(vector<int>&arr1, vector<int>&arr2){
    int n1 = arr1.size();
    int n2= arr2.size();
    int i=0,j=n1;
    while(i<=j){
        int px= i+(j-i)/2;
        int py= (n1+n2+1)/2 - px;

        int x1 = px>0 ? arr1[px-1] : INT_MIN;
        int x2 = py>0 ? arr2[py-1] : INT_MIN;
        int x3 = px<n1 ? arr1[px] : INT_MAX;
        int x4 = py<n2 ? arr2[py] : INT_MAX;
        
         if(x1<=x4 && x2<= x3){
            if((n1+n2)%2==0) 
            return (max(x1,x2) + min(x3,x4))/2.0;
            else  return max(x1,x2)/1.0;
         }
         else if(x1>x4)  j = px-1;
         else i = px+1;
        
    }
    return -1;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2 = nums2.size();
        if(n1<=n2)
         return fun(nums1,nums2);
       return fun(nums2,nums1);
    }
};