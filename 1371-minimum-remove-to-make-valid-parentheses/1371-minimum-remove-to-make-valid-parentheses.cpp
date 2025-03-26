class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int countOpenBracket = 0;
        string firstPass = "";
        
        // First Pass: Remove Extra ')'
        for (char c : s) {
            if (c == '(') {
                countOpenBracket++;
            } 
            else if (c == ')') {
                if (countOpenBracket == 0) continue; // Ignore unmatched ')'
                countOpenBracket--;
            }
            firstPass += c;
        }

        // Second Pass: Remove Extra '(' (Efficiently)
        vector<char> ans;
        int countCloseBracket = 0;
        
        for (int i = firstPass.length() - 1; i >= 0; i--) {
            char c = firstPass[i];

            if (c == ')') {
                countCloseBracket++;
            } 
            else if (c == '(') {
                if (countCloseBracket == 0) continue; // Ignore unmatched '('
                countCloseBracket--;
            }
            ans.push_back(c);
        }

        // Reverse to get the correct order
        reverse(ans.begin(), ans.end());

        return string(ans.begin(), ans.end());
    }
};
