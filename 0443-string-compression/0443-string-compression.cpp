class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        int count = 1;
        // char ch = chars[0];

        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == chars[i - 1])
                count++;
            else {
                chars[pos++] = chars[i - 1];
                if (count > 1) {
                    string digits = to_string(count);
                    for (char c : digits) {
                        chars[pos++] = c;
                    }
                }
                count = 1;
                // ch = chars[i];
            }
        }
        
        chars[pos++] = chars.back();
        if (count > 1) {
            string digits = to_string(count);
            for (char c : digits) {
                chars[pos++] = c;
            }
        }

        return pos;
    }
};