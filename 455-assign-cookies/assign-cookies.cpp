class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        for(int i=0;i<n;i++)
        pq1.push(g[i]);
        for(int i=0;i<m;i++)
        pq2.push(s[i]);
        int count =0;
        while((!pq1.empty()) && (!pq2.empty())){
            int gi = pq1.top();
            int sj = pq2.top();
            if(sj>=gi){
                count++;
                pq1.pop();
                pq2.pop();
            }
            else
            pq2.pop();
        }
        return count;
    }
};