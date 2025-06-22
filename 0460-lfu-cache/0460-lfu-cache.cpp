class node{
public:
   int key;
   int value;
   int cnt;//freq of node
   node* next;
   node* prev;
   node(int k,int v){
       key=k;
       value=v;
       cnt=1;
       next=NULL;
       prev=NULL;
   }
};
class List{
public:
     node* head=new node(-1,-1);
     node* tail=new node(-1,-1);
     int size;
     List(){
        head->next=tail;
        tail->prev=head;
        size=0;
     }
     void deletenode(node* curr){
          node* prevnode=curr->prev;
          node* nextnode=curr->next;
          prevnode->next=nextnode;
          nextnode->prev=prevnode;
          size--;
     }
     void insertnode(node* curr){
           node* headnext=head->next;
           head->next=curr;
           curr->prev=head;
           curr->next=headnext;
           headnext->prev=curr;
           size++;
     }
};
class LFUCache {
public:
    unordered_map<int,node*> mp;
    unordered_map<int,List*> fql;
    int cap;
    int minfreq;
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=0;
    }
    void update(node* req){
         List* l=fql[req->cnt];
         l->deletenode(req);
         if(minfreq == req->cnt && l->size == 0){
            minfreq++;
         }
         List* newlist;
         if(fql.find(req->cnt+1) != fql.end()){
            newlist=fql[req->cnt+1];
         }else{
            newlist=new List();
         }
         req->cnt=req->cnt+1;
         newlist->insertnode(req);
         fql[req->cnt]=newlist;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())return -1;

        node* req=mp[key];
        update(req);
        return req->value;
    }
    
    void put(int key, int value) {
         if(mp.find(key) != mp.end()){
            node* req=mp[key];
            req->value=value;
            update(req);
         }else{
            if(mp.size() == cap){
               List* l=fql[minfreq];
               mp.erase(l->tail->prev->key);
               l->deletenode(l->tail->prev);
            }
            minfreq=1;
            node* newnode=new node(key,value);
            List* newlist;
            if(fql.find(minfreq) != fql.end()){
                newlist=fql[minfreq];
            }else{
                newlist=new List();
            }
            newlist->insertnode(newnode);
            mp[key]=newnode;
            fql[minfreq]=newlist;
         }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */