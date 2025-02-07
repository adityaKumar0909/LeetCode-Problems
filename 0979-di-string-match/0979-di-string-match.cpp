class Solution {
public:
    vector<int> diStringMatch(string s) {

        vector<int> ans;

        int size = s.length();
        int small = 0;
        int large = size;

        for(int i=0;i<s.length();i++){
            if(s[i]=='I'){
                ans.push_back(small);
                small++;
            }
            else{
                ans.push_back(large);
                large--;
            }
        }

        ans.push_back(small);

        return ans;
        
    }
};