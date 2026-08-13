class StockSpanner {
public:
int i;
stack<int>st;
vector<int>arr;
    StockSpanner() {
         i=0;
    }
    
    int next(int price) {
        while(!st.empty() && arr[st.top()]<=price) st.pop();
        int ans =1;
        if(st.empty()) 
        ans = i+1;
        else ans = i-st.top();
        st.push(i);
        arr.push_back(price);
        i++;
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */