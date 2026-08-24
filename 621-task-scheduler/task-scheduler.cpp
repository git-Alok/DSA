class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        int sum =0;
        vector<int>freq(26,0);
        for(auto c : tasks)
        freq[c-'A']++;
       priority_queue<int>pq;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>0)
            pq.push(freq[i]);
        }
        while(!pq.empty()){
            vector<int>temp;
            int t = pq.size();
            for(int i=0;i<=n;i++){
                if(!pq.empty())
                {
                   int x = pq.top();
                   pq.pop();
                   x--;
                   if(x>0) temp.push_back(x);
                }
                else break;
            }
            for(auto k : temp) pq.push(k);

            if(pq.size()>0) sum += (n+1);
            else sum += t;

        }
    return sum;
    }
};