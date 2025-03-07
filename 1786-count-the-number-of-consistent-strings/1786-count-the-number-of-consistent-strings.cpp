class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> map(26,0);
        for(auto &ch:allowed){
            map[ch-'a']=true;
        }
        
        int count=0;
        for(auto &word:words){

            bool isNotFound = false;

            for(auto &ch:word){
                if(!map[ch-'a']){
                isNotFound  = true;
                break;}
            }

            if(!isNotFound) count++;
        }

        return count;


    }
};