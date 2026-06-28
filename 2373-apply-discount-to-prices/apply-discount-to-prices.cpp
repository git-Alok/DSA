class Solution {
public:
    string discountPrices(string sentence, int discount) {
        int n=sentence.size();
        unordered_map<int, string>mp;
        int i=0;
        while(i<n){
            if(sentence[i]=='$' && (i==0 || (i>0 && sentence[i-1]==' '))){
                long long num = 0;
                int j = i+1;
                while(j<n && sentence[j]>='0' && sentence[j]<='9'){
                    num*=10;
                    num+=(sentence[j]-'0');
                    j++;
                }
                if(j<n && sentence[j]!=' '){
                     i=j;
                     continue;
                }
                 if(num==0){
                    i=j;
                    continue;
                }
                
                double price = (double)num - (((double)num * discount) / 100.0);
               ostringstream out;
                out << fixed << setprecision(2) << price;

                 mp[num] = out.str();
                i=j;
                continue;
            }
            i++;
        }
        // for(auto it = mp.begin(); it!=mp.end();it++)
        // {
        //     cout<<it->first<<" "<<it->second<<endl;
        // }

        string ans ="";
         i=0;
        while(i<n){
             if(sentence[i]=='$' && (i==0 || (i>0 && sentence[i-1]==' '))){
                long long num = 0;
                int j = i+1;

                while(j<n && sentence[j]>='0' && sentence[j]<='9'){
                    num*=10;
                    num+=(sentence[j]-'0');
                    j++;
                }

                 if(j<n && sentence[j]!=' '){
                    ans+=sentence.substr(i,j-i);
                     i=j;
                     continue;
                }
                if(num==0){
                    ans+='$';
                    i=j;
                    continue;
                }
                ans+='$';
                ans+=mp[num];
               i=j;
               continue;
             }
             ans+= sentence[i];
             i++;
        }
return ans;
        
    }
};