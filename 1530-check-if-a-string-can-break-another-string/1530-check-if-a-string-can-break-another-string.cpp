class Solution {
public:
    string countSort(string s) {
        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string sortedStr;
        for (int i = 0; i < 26; i++) {
            sortedStr.append(freq[i], 'a' + i);
        }

        return sortedStr;
    }

    bool checkIfCanBreak(string s1, string s2) {
        s1 = countSort(s1);
        s2 = countSort(s2);

        bool doesS2broke = true;
        bool doesS1broke = true;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] > s2[i]) doesS2broke = false;
            if (s1[i] < s2[i]) doesS1broke = false;
        }

        return doesS2broke || doesS1broke;
    }
};
