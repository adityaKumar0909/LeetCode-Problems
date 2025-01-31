class Solution {
public:
    int longestBeautifulSubstring(string str) {

        vector<int> arr(128, -1);

        int s = 0;
        int e = 1;

        int len = str.length();

        arr[str[0]] = 0;

        int maxWindowSize = INT_MIN;

        for (e = 1; e < len; e++) {
            // If current char is lexicographically bigger or equal store it's
            // position
            if (str[e] >= str[e - 1]) {
                arr[str[e]] = e;
            } else {
                // Check if we have all the vowels
                if (arr['a'] != -1 && arr['e'] != -1 && arr['i'] != -1 &&
                    arr['o'] != -1 && arr['u'] != -1) {
                    maxWindowSize = max(maxWindowSize, e - s);
                }

                // Shrink window
                s = e;

                // reset them
                arr['a'] = -1;
                arr['e'] = -1;
                arr['i'] = -1;
                arr['o'] = -1;
                arr['u'] = -1;

                // Store current character index
                arr[str[e]] = e;
            }
        }

        // Check again
        /*
         * Because what if string is aeiou
         * s will be at 0
         * e will be out of bound
         * so we dont compare again we wont get the answer 5 here as maxWindow
         * wont ever compare until unless it founds a pair which is
         * lexicographically smaller in order
         */
        if (arr['a'] != -1 && arr['e'] != -1 && arr['i'] != -1 &&
            arr['o'] != -1 && arr['u'] != -1) {
            maxWindowSize = max(maxWindowSize, e - s);
        }

        return maxWindowSize == INT_MIN ? 0 : maxWindowSize;
    }
};