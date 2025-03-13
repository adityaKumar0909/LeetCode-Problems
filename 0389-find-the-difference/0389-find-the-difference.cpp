class Solution {
public:
    char findTheDifference(string s, string t) {
       //frequency of letters
       vector<int> freq(26,0);
       vector<int> freq2(26,0);

       for(auto x:s){
        freq[x-'a']++;
       }

        for(auto x:t){
        freq2[x-'a']++;
       }

       char ans;

       for(int i=0;i<26;i++){
        if(freq[i]!=freq2[i] ){ ans='a'+i;
        cout<<ans;
        break;
        }
       }

       

       return ans;




    }
};