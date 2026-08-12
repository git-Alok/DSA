class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            prefix[i][j] = matrix[i][j]-'0';
        }
        // /prefix sum
      for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(prefix[i][j]==0) continue;
            prefix[i][j]  = prefix[i][j]+prefix[i-1][j];
        }
      }

      vector<vector<int>>nsl(n,vector<int>(m,0));
      vector<vector<int>>nsr(n,vector<int>(m,0));
      

      for(int i=0;i<n;i++){
        stack<int>st;
        for(int j=0;j<m;j++){
            while(!st.empty() && prefix[i][st.top()]>=prefix[i][j])
            st.pop();
            if(st.empty()) nsl[i][j] = -1;
            else nsl[i][j] = st.top();
            st.push(j);
        }
      }


       for(int i=0;i<n;i++){
        stack<int>st;
        for(int j=m-1;j>=0;j--){
            while(!st.empty() && prefix[i][st.top()]>=prefix[i][j])
            st.pop();
            if(st.empty()) nsr[i][j] = m;
            else nsr[i][j] = st.top();
            st.push(j);
        }
      }

      int ans =0 ;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int dist = nsr[i][j]-nsl[i][j]-1;
            int val = dist*prefix[i][j];
            ans = max(ans,val);
        }
      }

    //   for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //     cout<<prefix[i][j]<<" ";
    //     cout<<endl;
    //   }

    //         for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //     cout<<nsl[i][j]<<" ";
    //     cout<<endl;
    //   }

    //         for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //     cout<<nsr[i][j]<<" ";
    //     cout<<endl;
    //   }
      return ans;
    }
};