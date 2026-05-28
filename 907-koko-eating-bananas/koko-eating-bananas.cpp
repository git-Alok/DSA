class Solution {
public:
bool check(vector<int>& piles, int h,int k){
    int hr=0;
    for(int i=0;i<piles.size();i++){
            if(piles[i]<=k)
            hr++;
            else {
                int rem=piles[i]%k;
                if(rem==0)
                hr+=(piles[i]/k);
                else 
                hr+=((piles[i]/k)+1);
            }
            if(hr>h) return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int i=1,j=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            bool possible=check(piles,h,mid);
            if(possible==1){
                ans=mid;
                j=mid-1;
            }
            else 
            i=mid+1;
        }
        return ans;
    }
};