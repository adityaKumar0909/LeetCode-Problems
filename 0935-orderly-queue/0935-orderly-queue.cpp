class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        if(k>1){
        int size = s.length();
        vector<char> arr;
        string ans;

        for(int i=0;i<size;i++){
            arr.push_back(s[i]);
        }
        
        
        sort(arr.begin(),arr.end());
        for(auto x:arr) ans+=x;
        return ans;
        }

        
        int i=0;
        string ans = s ;
        string lastWord = s;
        while(i<s.length()){

            string temp = lastWord.substr(1)+lastWord[0];
            
            if(temp < ans){
                ans = temp;
            }
            cout<<endl;

            lastWord = temp;
            i++; 

            
           
        }
        
        return ans;
        
    }
};