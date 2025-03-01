class Solution {
public:
    string arrangeWords(string text) {
        vector<string> words;
        text[0] = tolower(text[0]); 

        istringstream iss(text);
        string word;
        int count = 0;
        
        
        while (iss >> word) {
            words.push_back(word);
        }

        
        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });


        string ans = "";
        for (string &w : words) {
            ans += w + " ";
        }

        ans.pop_back();
        ans[0] = toupper(ans[0]); 

        return ans;
    }
};
