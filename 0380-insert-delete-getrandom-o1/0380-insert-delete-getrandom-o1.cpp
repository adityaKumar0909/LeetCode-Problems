class RandomizedSet {
public:

    vector<int> arr;
    unordered_map<int,int> map;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
      if(map.find(val)!=map.end()) return false;
      //For storing index of val
      map[val] = arr.size();
      arr.push_back(val);
      return true;

    }
    
    bool remove(int val) {


     if(map.find(val)!=map.end()){
        int temp  = arr.back();
        int index = map[val];

        arr[index] = temp;
        map[temp] = index;

        arr.pop_back();
        map.erase(val);

        return true;

     }
     else{
        return false;
     }

        
    }
    
    int getRandom() {
        if (arr.empty()) return -1;
     return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */