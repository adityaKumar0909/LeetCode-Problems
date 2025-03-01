class Solution {
public:
    static bool cmp(pair<string,int> &a,pair<string,int> &b){
        int n = a.first.length();
        int m = b.first.length();

        if(n!=m) return n<m;
        
        return a.second<b.second;
        


    }
    string arrangeWords(string text) {
        vector<pair<string , int>> pairs;
        int n = text.length();
        string word="";
        int count=0;
        text[0] =tolower(text[0]);
        
        for(int i=0;i<n;i++){
            if(text[i]==' '){
                i++;
                pairs.push_back({word,count});
                count++;
                word="";
            }
            word+=text[i];
        }
        if(word!="")
        pairs.push_back({word,count});

        // for(auto x:pairs ){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        sort(pairs.begin(),pairs.end(),cmp);
        string ans ="";
        for(int i=0;i<pairs.size()-1;i++){
            ans+=pairs[i].first+" ";
        }
        ans+=pairs[pairs.size()-1].first;
        ans[0] =toupper(ans[0]); 

        return ans;
        
    }
};