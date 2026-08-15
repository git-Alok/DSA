class LRUCache {
public:
class node{
    public:
    int key;
    int data ;
    node*prev, *next;
    node(int k,int val){
        key = k;
        data = val;
        prev = next = NULL;
    }
};

 node*first;
 node*last;
unordered_map<int,node*>mp;
int cap= 0;
    LRUCache(int capacity) {
        first = new node(-1,-1);
        last = new node(-1,-1);
        first->next = last;
        last->prev = first;  
        cap = capacity;
    }

    void insert(int key , int value){
        node*newnode = new node(key,value);
        node*newnode_prev = first;
        node*newnode_next = first->next;
        newnode_prev->next = newnode;
        newnode->prev = newnode_prev;
        newnode->next = newnode_next;
        newnode_next->prev = newnode;
        mp[key] = newnode;
        return ;

    }
    void del(int key){
        node*curr = mp[key];
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        mp.erase(key);
        delete curr;
        return ; 
    }

    int get(int key) {
        int val = -1;
        if(mp.contains(key))
        {
            node*curr = mp[key];
            val = curr->data;
            del(key);
            insert(key,val);
        }
        return val;
    }
    
    void put(int key, int value) {
        if(mp.contains(key))
        {
            node*curr = mp[key];
            int val = curr->data;
            del(key);
            insert(key,value);
        }
        else if(mp.size()>=cap){
           int k = last->prev->key;
           int v = last->prev->data;
           del(k);
           insert(key,value);
        }
        else{
            insert(key,value);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */