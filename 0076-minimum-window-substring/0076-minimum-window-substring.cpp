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

            // If character is in T , increase it's freq in map2
            if (mpp1[endChar] > 0) {
                if (mpp2[endChar] < mpp1[endChar]) {
                    count++;
                }
                mpp2[endChar]++;
            }

            // If count = required characters , count minWindow size
            while (count == required) {
                // Find minimum window
                if (end - start + 1 < minWindowSize) {
                    minWindowSize = end - start + 1;
                    minStart = start;
                }

                // If character exist in map1 reduce it's window
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

        return minWindowSize == INT_MAX ? "": s.substr(minStart, minWindowSize);
    }
};