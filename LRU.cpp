
#include <iostream>
#include <stdexcept>
#include<map>
#include<list>


class LRUCache {
public:
    std::list<std::pair<int, int>> values;//pair<key,value>
    std::map<int, std::list<std::pair<int, int>>::iterator> keys;
    int limit;
    int currentSize=0;


    LRUCache(int capacity) {
        limit = capacity;

    }

    int get(int key) {
        std::list<std::pair<int, int>>::iterator it;
        try {
            it = keys.at(key);
          
        }
        catch (const std::out_of_range& oor) {
            return -1;
        }

        int res = it->second;
        int rem = values.back().second;
        values.erase(it);
        keys.erase(key);
        values.push_front({ key, res });
        keys[key] = values.begin();      
        return res;

    }

    void put(int key, int value) {
        std::list<std::pair<int, int>>::iterator it;
        try {
            it = keys.at(key);
        }
        catch (std::out_of_range oor) {
            if (currentSize < limit) {
                currentSize++;
            }
            else {
                int rem = values.back().first;
                values.pop_back();
                keys.erase(rem);

            }
            values.push_front({ key, value });
            keys[key] = values.begin();
            return;
        }

        values.erase(keys[key]);
        values.push_front({ key, value });
        keys[key] = values.begin();

    }
  
};




int main()
{
    LRUCache *cache = new LRUCache(3 /* capacity */);
   
    cache->put(1, 1);
    cache->put(2, 2);   
    cache->put(3, 3); 
    cache->put(4, 4);  
    cache->get(4);      
    cache->get(3);  
    cache->get(2);  
    cache->get(1);    
    cache->put(5,5);
    cache->get(1); 
    cache->get(2); 
    cache->get(3); 
    cache->get(4); 
    cache->get(5);

}
 
