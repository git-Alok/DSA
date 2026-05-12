class Solution {
public:
bool check(int val,vector<vector<int>>& tasks){
        for(int i=0;i<tasks.size();i++){
            if(val<tasks[i][1])
            return false;
            val-=tasks[i][0];
        }
        return true;
}
    int minimumEffort(vector<vector<int>>& tasks) {
        auto lamda=[](auto t1,auto t2){
            int d1=t1[1]-t1[0];
            int d2=t2[1]-t2[0];
            return d1>d2;
        };
        sort(tasks.begin(),tasks.end(),lamda);
        int st=0,end=1e9;
        int ans=end;
        while(st<=end){
           int mid=st+(end-st)/2;
           if(check(mid,tasks)){
                ans=mid;
                end=mid-1;
           }
           else 
           st=mid+1;
        }
        return ans;
    }
};