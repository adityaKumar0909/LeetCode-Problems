class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        int n = strs.size();
        unordered_map<string ,vector<string>> mp;
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){

            // vector<string> list;

            //map frequency
            vector<int> freq(26,0);
            for(auto x:strs[i]) freq[x-'a']++;

            string currentkey = "";

            for(auto x:freq) currentkey+=x+'0';

            mp[currentkey].push_back(strs[i]);

        }
        for(auto & pair:mp){
            ans.push_back(pair.second);
        }


        return ans;
        
    }
};