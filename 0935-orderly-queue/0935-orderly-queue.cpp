class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1){
        sort(s.begin(),s.end());
        return s;
        }

        
        int i=0;
        string ans = s ;
        string lastWord = s;
        while(i<s.length()){

            string temp = lastWord.substr(1)+lastWord[0];
            
            if(temp < ans){
                ans = temp;
            }
            lastWord = temp;
            i++; 

            
        }
        
        return ans;
        
    }
};