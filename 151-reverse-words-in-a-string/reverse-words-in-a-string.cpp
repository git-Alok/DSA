class Solution {
public:
    string reverseWords(string s) {
        vector<string>arr;
        string temp="";
        for(int i=0;i<s.size();i++){
             if(s[i]==' ')
             {
                if(temp.size()>0)
                  arr.push_back(temp);
                temp = "";
                continue;
             }
             temp+=s[i];
        }
        if(temp.size()>0) arr.push_back(temp);
      reverse(arr.begin(),arr.end());
    temp ="";
    for(int i=0;i<arr.size();i++){
        temp+=arr[i];
        if(i<arr.size()-1) temp+=" ";
    }
    return temp;
    }
};