class MinStack {
public:
stack<int>st;
stack<int>min_st;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) {
            st.push(value);
            min_st.push(value);
            return ;
        }
        st.push(value);
        int mini = min(value,min_st.top());
        min_st.push(mini);
        return ;
    }
    
    void pop() {
     st.pop();
     min_st.pop();
     return;
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */