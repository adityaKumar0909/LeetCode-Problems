class Solution {
public:
    string customSortString(string order, string s) {

        //Take a freq vector
        vector<int> freq(26,0);

        for(auto x:s){
            freq[x-'a']++;
        }
        
        string ans="";
        for(int i=0;i<order.size();i++){

            for(int j=0;j<freq[order[i]-'a'];j++){
                ans+=order[i];
            }
            freq[order[i]-'a']=0;

        }
        // cout<<ans<<endl;

        //For left out element 
        for(int i=0;i<freq.size();i++){
            if(freq[i]>=1){
                for(int j=0;j<freq[i];j++){
                    ans+='a'+i;
                }
            }
        }
        // cout<<ans;

        return ans;
        
    }
};