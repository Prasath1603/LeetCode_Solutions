class MyCalendar {
public:
    MyCalendar() {
        
    }
    set<pair<int,int>> s;
    bool book(int start, int end) {
        pair<int,int> target = {start,end};
        auto it = s.lower_bound(target);

        if(it != s.end() && it->first < end){
            return false;
        }
        if(it != s.begin()){
            auto prevv = prev(it);
            if(prevv->second > start){
                return false;
            }
        }
        s.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */