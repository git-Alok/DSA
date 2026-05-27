class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
     vector<int>lower(26,-1);
     vector<int>upper(26,-1);
        for(int i=0;i<n;i++){
           if(word[i]>='A' && word[i]<='Z')
            {
              if(upper[word[i]-'A']==-1)
              upper[word[i]-'A']=i;

            }
            else {
                lower[word[i]-'a']=i;
            }
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(lower[i]!=-1 && upper[i]!=-1){
                if(lower[i]<upper[i]) count++;
            }
        }
        return count;
    }
};