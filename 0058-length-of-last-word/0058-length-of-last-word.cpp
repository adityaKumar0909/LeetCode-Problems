class Solution {
public:
    int lengthOfLastWord(string s) {

        int wordLength = 0;

        string word = "";

        for(int i=0;i<s.length();i++){
            if(s[i] == ' ' && word.length()!=0){
                wordLength = word.length();
                word = "";
            }
            else if(s[i]!=' ')
            word+=s[i];
        }

       

        if(word.length() == 0) return wordLength;
        else return word.length();

        return wordLength;

        
        
    }
};