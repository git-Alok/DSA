class Solution {
public:
set<string>all;
void generate(int i,string &s,int count,string &temp){
    if(count==0) all.insert(temp);
    if(i>=s.size()) return ;
    if(count<0) return ;
    generate(i+1,s,count,temp);
    temp.push_back(s[i]);
    int k = count;
    if(s[i]=='(') 
    k = count+1;
    else if(s[i]==')') k = count-1;
    generate(i+1,s,k,temp);
    temp.pop_back();

}
    vector<string> removeInvalidParentheses(string s) {
        string temp ;
        generate(0,s,0,temp);
        vector<string>ans;
       int maxi = 0; 
        for(auto &c : all){
            if((int)c.size()>maxi)
            maxi = (int)c.size();
        }
        for(auto &c : all) {
            if(maxi == c.size())
            ans.push_back(c);
        }
     return ans;
    }
};