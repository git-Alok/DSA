class MedianFinder {
public:
priority_queue<int>left;
priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
         
    }
    
    void addNum(int num) {
        if(left.size()<=right.size())
        left.push(num);
        else right.push(num);

        if(!left.empty() && !right.empty()){
            if(left.top()>right.top())
            {
                int t1 = left.top();
                int t2 = right.top();
                left.pop();
                right.pop();
                left.push(t2);
                right.push(t1);
            }
        }
        return ;
    }
    
    double findMedian() {
        if(left.size()==right.size())
        return (left.top()+right.top())/2.0;

        return left.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */