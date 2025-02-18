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
        string smallest = s;
        string lastWord = s;
        while(i<s.length()){

            string temp = lastWord.substr(1)+lastWord[0];
            cout<<"old word:"<<lastWord<<endl;
            cout<<"new word:"<<temp<<endl;
            if(temp < ans){
                ans = temp;
                cout<<"ans:"<<ans<<endl;
            }
            cout<<endl;

            lastWord = temp;
            i++; 

            
           
        }
        
        cout<<"ans:"<<smallest<<endl;
        

        return ans;


        
    }
};