class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        int count=0;
        while(i<n && s[i]!=' ')
        { 
           if(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='o' || s[i]=='u')
            count++;
            i++;
        }

        if(i<n && s[i]==' ')
        i++;
        int x=i;
        int c=0;
        while(i<n){
           if(s[i]!=' '){
             if(s[i]=='a'||s[i]=='e'||s[i]=='i'|| s[i]=='o' || s[i]=='u')
             c++;
           }
           else {
            if(c==count){
                int y=i-1;
                while(x<y)
                {
                    swap(s[x],s[y]);
                    x++,y--;
                }
            }
            x=i+1;
            c=0;
           }
           i++;
        }

        if(c==count){
        int y=i-1;
        while(x<y){
            swap(s[x],s[y]);
            x++,y--;
        }
        }
        return s;

    }
};