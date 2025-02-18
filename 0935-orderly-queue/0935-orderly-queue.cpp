class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1){
        sort(s.begin(),s.end());
        return s;
        }

        
        int i=0;
        string ans = s ;
        
        for(int i=0;i<s.length();i++){
            s = s.substr(1)+s[0]; 
            if(s < ans){
                ans = s;
            } 
        }
        
        return ans;
        
    }
};