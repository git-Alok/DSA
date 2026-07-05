class Solution {
public:
    bool canBeValid(string s, string locked) {
        int left =0;
        int right =0;
        int n = s.size();
        if(n%2!=0) return false;
        for(int i=0;i<n;i++){
            if(locked[i]=='0' || s[i]=='(')
            left+=1;
            else left-=1;
            if(left<0) return false;
        }

        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0'|| s[i]==')')
            right++;
            else right--;
            if(right<0) return false;
        }
        return true;
    }
};