class node{
public:
    int key;
    int value;
    node* prev;
    node* next;
    node(int k,int v){
        key=k;
        value=v;
        prev=NULL;
        next=NULL;
    }
    
};
class LRUCache {
public:
    int cap;
    unordered_map<int,node*> mp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deletenode(node* curr){
         node* prevnode=curr->prev;
         node* nextnode=curr->next;
         prevnode->next=nextnode;
         nextnode->prev=prevnode;
    }
    void insertnode(node* curr){
           
         node* headnext=head->next;
         head->next=curr;
         curr->prev=head;
         curr->next=headnext;
         headnext->prev=curr;

    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;

        node* req=mp[key];
        deletenode(req);
        insertnode(req);
        return req->value;
    }
    
    void put(int key, int value) {
         if(mp.find(key) != mp.end()){
            node* req=mp[key];
            req->value=value;
            deletenode(req);
            insertnode(req);
         }else{
            if(mp.size() == cap){
                node* lastnode=tail->prev;
                mp.erase(lastnode->key);
                deletenode(lastnode);
            }
            node* newnode=new node(key,value);
            mp[key]=newnode;
            insertnode(newnode);
         }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */