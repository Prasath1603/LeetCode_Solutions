class KthLargest {
public:
    priority_queue<int, vector<int>, greater<>> p;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i : nums) {
            add(i);
        }
    }

    int add(int val) {
        if(p.size()<k){
            p.push(val);
        }
        else if(val>p.top()){
            p.pop();
            p.push(val);
        }
        return p.top();

    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */