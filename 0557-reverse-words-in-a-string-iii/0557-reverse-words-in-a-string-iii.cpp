class Solution {
public:

    string ReverseWord(string word){
        int n = word.size();
        for(int i=0;i<word.length()/2;i++){
            swap(word[i],word[n-1-i]);
        }
        return word;

    }
    string reverseWords(string s) {

        string word = "";
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                i++;
                ans+=ReverseWord(word)+" ";
                word="";

            }
            word+=s[i];
        }

        ans+=ReverseWord(word);

        return ans;
        
    }
};