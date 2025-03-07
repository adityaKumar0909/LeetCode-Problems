class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> map;
        for(auto &ch:allowed){
            map[ch]++;
        }
        
        int count=0;
        for(auto &word:words){

            bool isNotFound = false;

            for(auto &ch:word){
                if(map.count(ch)==0) isNotFound = true;
            }

            if(!isNotFound) count++;
        }

        return count;


    }
};