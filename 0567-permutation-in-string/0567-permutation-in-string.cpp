class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int> freq(128, 0);
        vector<int> freq2(128, 0);

        int uniqueChar = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (freq[s1[i]] == 0)
                uniqueChar++;
            freq[s1[i]]++;
        }

        int windowSize = s1.length();

      
        int start = 0;
        int end = 0;
        int count = 0;

        while (end < s2.length()) {

            // Adding new char to window
            if (freq[s2[end]] > 0) {

                freq2[s2[end]]++;

                if (freq2[s2[end]] == freq[s2[end]])
                    count++;

            }

            // Remove old elements
            if (end - start + 1 > s1.length()) {
             
                if (freq[s2[start]] > 0) {
                    if (freq[s2[start]] == freq2[s2[start]])
                        count--;
                freq2[s2[start]]--;

                }
                start++;
            }

            if (count == uniqueChar) {
                return true;
            }

            end++;
        }

        return false;
    }
};