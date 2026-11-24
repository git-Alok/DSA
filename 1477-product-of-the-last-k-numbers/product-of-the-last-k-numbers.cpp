class ProductOfNumbers {
public:
vector<int>arr;
    ProductOfNumbers() {

    }
   void add(int num) {
        int n = arr.size();
        if(n==0) arr.push_back(num);
        else arr.push_back(arr[n-1]*num);
        if(num==0) arr.clear();
    }
    
    int getProduct(int k) {
        int n = arr.size();
        if(k>n) return 0;
        if(n==k) return arr[n-1];
        return arr[n-1]/arr[n-k-1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */