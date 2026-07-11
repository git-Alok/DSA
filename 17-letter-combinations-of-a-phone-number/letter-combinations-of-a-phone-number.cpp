class Solution {
public:
void generate(int i,int n,string &s, map<char,string>&mp,vector<string>&ans,string &digits){
    if(i>=n){
        ans.push_back(s);
        return ;
    }
    for(int k=0;k<mp[digits[i]].size();k++){
        s.push_back(mp[digits[i]][k]);
        generate(i+1,n,s,mp,ans,digits);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        map<char,string>mp;
        for(int i=0;i<n;i++)
        {
            if(digits[i]=='2')
            mp['2'] = "abc";
            else if(digits[i]=='3')
            mp['3']= "def";
            else if(digits[i]=='4')
            mp['4'] = "ghi";
            else if(digits[i]=='5')
            mp['5'] = "jkl";
            else if(digits[i]=='6')
            mp['6'] = "mno";
            else if(digits[i]=='7')
            mp['7'] = "pqrs";
            else if(digits[i]=='8')
            mp['8'] = "tuv";
            else if(digits[i]=='9')
            mp['9'] = "wxyz";
        }
        vector<string>ans;
        string s;
        generate(0,n,s,mp,ans,digits);
        return ans;

    }
};