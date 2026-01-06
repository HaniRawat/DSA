class DinnerPlates {
private:
    vector<int> v;
    set<int> st;
    int n;
public:
    DinnerPlates(int capacity) {
        n = capacity;
    }
    
    void push(int val) {
        if(st.empty()) v.push_back(val);
        else{
            int idx = *(st.begin());
            st.erase(st.begin());

            v[idx] = val;
        }
    }
    
    int pop() {
        while(v.size() > 0 && v.back() == -1){
            v.pop_back();
            auto it = st.find(v.size());
            if(it != st.end()) st.erase(it);
        }

        int n = v.size() - 1;
        if(n < 0) return -1;
        
        int x = v.back();
        v.pop_back();

        return x;
    }
    
    int popAtStack(int index) {
        int size = v.size();
        int stacks = (size / n) + (size % n != 0);
        if(index + 1 > stacks) return -1;

        int high = min(size-1,(index + 1)*n - 1);
        int low = max(0,(index * n));
        
        cout<<low<<" "<<high<<endl;
        while(high >= low && v[high] == -1) high--;
        if(high < low) return -1;

        int x = v[high];
        v[high] = -1;
        st.insert(high);

        return x;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */