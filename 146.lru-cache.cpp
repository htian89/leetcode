/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */
class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {
        
    }
    
    int get(int key) {
       auto it = cache_.find(key);
       if (it == cache_.end()) return -1;
       touch(it);
       return it->second.first;
    }
    
    void put(int key, int value) {
       auto it = cache_.find(key);
       if (it != cache_.end()) {
           touch(it);
       } else {
           if (cache_.size() == capacity_) {
               cache_.erase(used_.back());
               used_.pop_back();
           }
           used_.push_front(key);
       }
       cache_[key] = LII(value, used_.begin());
    }

private:
    typedef list<int> LI;
    typedef pair<int, LI::iterator> LII;
    typedef unordered_map<int, LII> HASHMAP; 
    void touch(HASHMAP::iterator it) {
        int key = it->first;
        used_.erase(it->second.second);
        used_.push_front(key);
        it->second.second = used_.begin();
    }
    LI used_;
    HASHMAP cache_;
    int capacity_ = 0;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

