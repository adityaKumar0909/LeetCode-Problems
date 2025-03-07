class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        

        //Mapping each code to each letter
        vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
        ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",
        ".--","-..-","-.--","--.."};

        unordered_map<string,int> map;

        for(auto &word:words){
            string currentChar = "";
            for(auto &ch:word){
                currentChar+=code[ch-'a'];
            }

            map[currentChar]++;

        }

        return map.size();
        
    }
};