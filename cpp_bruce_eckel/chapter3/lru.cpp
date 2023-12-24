LRUCache(int capacity)
    {
        vector<pair<int,int>> lru;
        map<int,int> findMap;
        int queueSize = capacity;
        // Write your code here
    }

    int get(int key)
    {
        return findMap[key];
        // Write your code here
    }

    void put(int key, int value)
    {
        if(findMap.find(key) != findMap.end()){
            findMap[key] = value;
        }
        if(lru.size() > queueSize){
            lru.pop_front();
        }
        lru.push_back({key,value});
        // Write your code here
    }
