class Solution {
public:
void fillque(queue<string>&q, string &num ,unordered_set<string>&st){
    for(int i=0;i<4;i++){
        char ch = num[i];
        char dec = ch=='9' ? '0' : ch+1;
        char inc = ch=='0' ? '9' : ch-1;

        num[i] = dec;
        if(!st.contains(num)){
           st.insert(num);
           q.push(num);
        }

        num[i] = inc;
        if(!st.contains(num)){
            st.insert(num);
            q.push(num);
        }

        num[i] = ch;
    }
}
    int openLock(vector<string>& deadends, string target) {
        int level = 0;
        unordered_set<string>st(begin(deadends),end(deadends));
        if(st.contains("0000")) return -1;
        queue<string>q;
        q.push("0000");
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                string num = q.front();
                q.pop();
                if(num==target) return level;

                fillque(q,num,st);
            }
           level++;
        }
        return -1;
    }
};