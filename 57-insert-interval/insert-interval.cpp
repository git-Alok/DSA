class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int s = 0;
        int e = n-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(intervals[mid][0]<=newInterval[0]){
                s = mid+1;
            }
            else e = mid-1;
        }
        intervals.insert(intervals.begin()+s,newInterval);
        n = intervals.size();
        vector<vector<int>>ans;
         s = intervals[0][0];
         e = intervals[0][1];
        for(int i=1;i<n;i++){
            if(e>=intervals[i][0]){
                e = max(e,intervals[i][1]);
            }
            else {
                ans.push_back({s,e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};