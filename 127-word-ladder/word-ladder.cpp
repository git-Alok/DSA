class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        unordered_map<string, bool>present_word;
        for(int i=0;i<n;i++){
            present_word[wordList[i]]=1;
        }
        queue<string>q;
        q.push(beginWord);
        int ans = 1;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                string s = q.front();
                if(s==endWord) return ans;
                q.pop();
                for(int j=0;j<s.size();j++){
                    for(char ch = 'a'; ch<='z';ch++){
                        string temp = s;
                        temp[j]=ch;
                        if(present_word[temp]==1){
                            q.push(temp);
                            present_word[temp] = 0;
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};