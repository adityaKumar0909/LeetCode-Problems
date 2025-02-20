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

    
    string findLongestWord(string s, vector<string>& dictionary) {

        string answer = "";

        

        for(auto word : dictionary){
            if(ifSubsequence(word,s)){
               
               if(word.length() > answer.length() ||
               (word.length() == answer.length() && word < answer)){
                answer=word;
               }

            }
        }

        

        return answer==""?"":answer;
        
    }
};