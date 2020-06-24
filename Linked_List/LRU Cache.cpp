/*
unordered_map<int,list<pair<int,int>>::iterator> mymap;

Iterator always stores address. 
So whenever you use iterator (say in a loop) then in order to access the element, 
you need to put a star before iterator variable. 
The value of map is declared iterator type, in other words, address type.

*/
class LRUCache
{
public:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> lookup; //storing address of entries of cache

    void renewPosition(int key, int value)
    {
        cache.erase(lookup[key]);
        cache.emplace_front(key, value);
        lookup[key] = cache.begin(); //address of new position stored in map
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        cache.clear();
        lookup.clear();
    }

    int get(int key)
    {
        if (lookup.find(key) != lookup.end())
        {
            renewPosition(key, (*lookup[key]).second);
            // return (*lookup[key]).second;
            //same as
            return lookup[key]->second;
        }
        return -1;
    }

    void put(int key, int value)
    {
        //case 1 : need to update as key already present in cache
        if (lookup.find(key) != lookup.end())
        {
            renewPosition(key, value);
        }
        else //case2 : need to add new (key,value) pair
        {
            cache.emplace_front(key, value);
            lookup[key] = cache.begin();
            if (cache.size() > cap)
            {
                lookup.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */