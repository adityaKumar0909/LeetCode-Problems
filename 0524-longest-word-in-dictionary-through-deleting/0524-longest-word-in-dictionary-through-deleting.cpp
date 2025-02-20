class Solution {
public:

    bool ifSubsequence(string word, string s){
        int i=0,j=0;
        while(i<s.length() && j<word.length()){
            if(s[i]==word[j]) j++;
            i++;
        }

        return j==word.length();
    }

    static bool cmp(string a , string b){
        if(a.length()!=b.length())
        return a.length()>b.length();
        else{
            return a<b;
        }
    }
    string findLongestWord(string s, vector<string>& dictionary) {

        sort(dictionary.begin(),dictionary.end(),cmp);

        for(auto word : dictionary){
            if(ifSubsequence(word,s)) return word;
        }

        return "";
        
    }
};