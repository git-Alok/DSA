// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int row=matrix.size(),col=matrix[0].size();
//         for(int i=0;i<row-1;i++){
//             for(int j=i+1;j<row;j++){
//                 swap(matrix[i][j],matrix[j][i]);
//             }
//         }
//         for(int i=0;i<row;i++){
//             int start=0,end=col-1;
//             while(start<end){
//                 swap(matrix[i][start],matrix[i][end]);
//                 start++;
//                 end--;
//             }
//         }
        
//     }
// };


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n=matrix.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j){
            int f=matrix[i][j];
            int s=matrix[j][i];
            matrix[i][j]=s;
            matrix[j][i]=f;
            }
        }
       }
       for(int i=0;i<n;i++){
        int s=0,e=n-1;
        while(s<e){
            swap(matrix[i][s],matrix[i][e]);
            s++,e--;
        }
       }
    }
};