class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        int j = 0;
        int n = s.length();

        while (j < n) {
            i = j;
            int end = min(j + k - 1, n - 1); 

            
            while (i < end) {
                swap(s[i], s[end]);
                i++;
                end--;
            }

            j += 2 * k;
        }

        return s;
    }
};
