class CustomStack {
public:
    vector<int> v;
    int size ;
    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if(v.size()!=size){
            v.push_back(x);
            // cout<<"push "<<x<<" ";
        }
    }
    
    int pop() {
        if(v.size()){
            int x = v.back();
            cout<<v.back();
            v.pop_back();
            return x;
        }
        return -1;
    }
    
    void increment(int k, int val) {
         for(int i = 0 ; i < k && i < v.size() ; i++)
            v[i]+=val;
          
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */