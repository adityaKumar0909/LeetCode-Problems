class Solution {
public:
    void funct(string& s, vector<string>& arr, int index) {
        if (index == s.length())
            {
                arr.push_back(s);
                return;
            }

        funct(s, arr, index + 1);

        string temp = s;
        if (isalpha(s[index])) {
            if (isupper(s[index]))
                s[index] += 32; 
            else if (islower(s[index]))
                s[index] -= 32;
         funct(s, arr, index + 1);
            
        }

    }

    vector<string> letterCasePermutation(string s) {
        vector<string> arr;
        funct(s, arr, 0);
        return arr;
    }
};