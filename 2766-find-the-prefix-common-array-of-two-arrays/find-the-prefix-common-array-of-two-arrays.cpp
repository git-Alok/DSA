class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        map<int,int>mp1;
        map<int,int>mp2;
        vector<int>ans(n);
        if(A[0]==B[0]) ans[0]=1;
        mp1[A[0]]++;
        mp2[B[0]]++;
        for(int i=1;i<n;i++){
            mp1[A[i]]++;
            mp2[B[i]]++;
            int count=0;
            int val1=A[i];
            int val2=B[i];
            if(val1==val2){
                ans[i]=1+ans[i-1];
            }
            else{
            count+=(min(mp1[val1],mp2[val1]));
            count+=(min(mp1[val2],mp2[val2]));
            count+=ans[i-1];
            ans[i]=count;
            }

          
        }
        return ans;
    }
};