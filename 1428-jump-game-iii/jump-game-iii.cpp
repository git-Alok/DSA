class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool>visit(n,0);
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            visit[top] = 1;
            if(arr[top]==0) return true;
            if(top-arr[top]>=0 && top-arr[top]<n && visit[top-arr[top]]==0){
                q.push(top-arr[top]);
                visit[top-arr[top]]=1;
            }
            if(top+arr[top]>=0 && top+arr[top]<n && visit[top+arr[top]]==0){
                q.push(top+arr[top]);
                visit[top+arr[top]]=1;
            } 
        }
       return false;
    }
};