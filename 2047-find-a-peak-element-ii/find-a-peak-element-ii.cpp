class Solution {
public:
int findrowindex(int mid, int n,vector<vector<int>>& mat){
    int idx = -1;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        if(mat[i][mid]>maxi)
        {
            maxi = mat[i][mid];
            idx = i;
        }
    }
    return idx;
}

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
            int i=0,j=m-1;
            while(i<=j){
                int mid = i+(j-i)/2;
                // int top = k==0 ? -1 : mat[k-1][mid];
                // int bottom = k==n-1 ? -1 : mat[k+1][mid];
                int f_row_idx = findrowindex(mid,n,mat);
                int left = mid ==0 ? -1 : mat[f_row_idx][mid-1];
                int right = mid == m-1 ? -1 : mat[f_row_idx][mid+1];
                if(mat[f_row_idx][mid]>left && mat[f_row_idx][mid]>right)
                {
                    return {f_row_idx,mid};
                }
                else if(mid<m-1 && mat[f_row_idx][mid]<mat[f_row_idx][mid+1])
                i=mid+1;
                else if(mid>0 && mat[f_row_idx][mid]<mat[f_row_idx][mid-1])
                j=mid-1;
                else i=mid+1;
            }       
        return {0,0};
    }
};