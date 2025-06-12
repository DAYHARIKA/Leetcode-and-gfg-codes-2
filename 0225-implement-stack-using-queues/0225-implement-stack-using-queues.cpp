class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size=q.size();
        q.push(x);
        for(int i=0;i<size;i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }else{
            int popped=q.front();
            q.pop();
            return popped;
        }
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }else{
            return q.front();
        }
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */