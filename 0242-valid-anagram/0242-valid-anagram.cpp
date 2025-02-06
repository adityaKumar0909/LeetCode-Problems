class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;
        vector<int> smap(27,0);
        vector<int> tmap(27,0);
        for(auto x:s){
            smap[x-'a']++;
        }

       

         for(auto x:t){
            tmap[x-'a']++;
        }

    

        for(int i=0;i<27;i++){
            if(smap[i]!=tmap[i])
            return false;
        }

        return true;
    }
};