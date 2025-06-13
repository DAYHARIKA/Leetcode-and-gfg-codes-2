class MinStack {
public:
    stack<pair<long,long>> st;
    int mini;
    MinStack() {
        mini=0;
    }
    
    void push(int val) {
         
         if(st.empty() || val < mini){
            mini=val;
         }
         st.push({val,mini});
    }
    
    void pop() {
        if(st.empty()){
            return;
        }else{
            pair<long,long> ans=st.top();
            st.pop();
            if(st.empty()){
                mini=0;
            }else if(ans.second == mini){
                pair<long,long> temp=st.top();
                mini=temp.second;
            }
        }
    }
    
    int top() {
        if(st.empty()){
            return 0;
        }else{
            pair<long,long> ans=st.top();
            return ans.first;
        }
    }
    
    int getMin() {
        if(st.empty()){
            return 0;
        }else{
            pair<long,long> ans=st.top();
            return ans.second;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */