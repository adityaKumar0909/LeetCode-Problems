class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false; 

        unordered_map<char, char> map1;
        unordered_map<char, char> map2;

        int n = s.length();

        for (int i = 0; i < n; i++) {
            char c1 = s[i], c2 = t[i];

            // If already mapped, check for consistency
            if ((map1.count(c1) && map1[c1] != c2) || 
                (map2.count(c2) && map2[c2] != c1)) {
                return false;
            }

            // Create new mappings
            map1[c1] = c2;
            map2[c2] = c1;
        }

        return true;
    }
};
