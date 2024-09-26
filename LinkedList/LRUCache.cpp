# include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class LRUCache {
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> dll;
    void moveTofront(int key) {
        //extract the key value pair
        auto it = mp[key];
        pair<int,int> kv = *it;
        //remove from dll
        dll.erase(it);
        //insert at beginning
        dll.push_front(kv);
        //update address
        mp[key] = dll.begin();
    }
public:
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        //if not found
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        //if found
        moveTofront(key);

        return mp[key]->second;
    }
    
    void put(int key, int value) {
        //update
        if(mp.find(key) != mp.end()) {
            moveTofront(key);
            mp[key]->second = value;
        }
        else {
            if(dll.size() == cap) {
                auto it = dll.back();
                int key = it.first;
                dll.pop_back();
                //remove from map
                mp.erase(key);
            }
            //insert in map
            dll.push_front({key,value});
            mp[key] = dll.begin();
        }
    }
};

int main() {
    LRUCache lRUCache(2);

    lRUCache.put(1, 1); 
    lRUCache.put(2, 2); 
    cout<<lRUCache.get(1)<<endl;   
    lRUCache.put(3, 3); 
    cout<<lRUCache.get(2)<<endl;    
    lRUCache.put(4, 4); 
    cout<<lRUCache.get(1)<<endl;    
    cout<<lRUCache.get(3)<<endl;;   
    cout<<lRUCache.get(4);
}