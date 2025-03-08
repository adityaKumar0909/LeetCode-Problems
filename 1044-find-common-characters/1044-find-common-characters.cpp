class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        //For counting frequency 
        vector<int> freq(26,0);

        //Find frequency of first word
        for(auto &ch:words[0]){
            freq[ch-'a']++;
        }

        for(auto &word:words){
        vector<int> temp(26,0);
            for(auto &ch:word){

                if(freq[ch-'a']){
                    freq[ch-'a']--;
                    temp[ch-'a']++;
                }
            }
            freq = temp;
        }

        
        vector<string> ans;

        for(int i=0;i<26;i++){
            while(freq[i]>0){
            string temp="";
            temp = 'a'+i;
            ans.push_back(temp);
            freq[i]--;
            }
        }

        return ans;
        
    }
};