class Solution {
public:
    string sortSentence(string s) {

        int maximum = INT_MIN;
        for(auto x:s){
            if(isdigit(x) && (x-'0')>maximum){
                maximum = x-'0';
            }
        }

        string answer="";

        vector<string> words(maximum,"");

        string word="";
        for(int i =0;i<s.length();i++){
            if(isdigit(s[i])){
                words[(s[i]-'0')-1] = word;
                word="";
                i++;
            }
            else
            word+=s[i];
        }

        for(auto x:words){
            if(!x.empty()){
            if (!answer.empty()) answer += " ";
            answer+=x;
            }
        }
        

        return answer;
        
    }
};