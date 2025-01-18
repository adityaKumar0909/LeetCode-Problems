class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";

        vector<int> mpp1(128, 0), mpp2(128, 0);

        // Frequency of characters in `t`
        for (char c : t) {
            mpp1[c]++;
        }

        int required = t.length();
        int count = 0;
        int minWindowSize = INT_MAX;
        int start = 0, end = 0;
        int minStart = 0;

        while (end < s.length()) {
            char endChar = s[end];
            if (mpp1[endChar] > 0) { 
                if (mpp2[endChar] < mpp1[endChar]) {  
                    count++;
                }
                mpp2[endChar]++;
            }

            while (count == required) {
                if (end - start + 1 < minWindowSize) {
                    minWindowSize = end - start + 1;
                    minStart = start;
                }

                char startChar = s[start];
                if (mpp1[startChar] > 0) {
                    mpp2[startChar]--;
                    if (mpp2[startChar] < mpp1[startChar]) {  
                        count--;
                    }
                }
                start++;
            }
            end++;
        }

        return minWindowSize == INT_MAX ? "" : s.substr(minStart, minWindowSize);
    }
};