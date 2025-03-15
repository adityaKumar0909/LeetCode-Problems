class Solution {
public:
    bool buddyStrings(string s, string goal) {

        // vector<int> freq1(26,0);
        // vector<int> freq2(26,0);

        // for(auto x:s) freq1[x-'a']++;
        // for(auto x:s) freq2[x-'a']++;

        // int unique1=0;
        // int unique2=0;
        // for(int i=0;i<26;i++){
        //     if(freq1[i]>=1) unique1++;
        //     if(freq2[i]>=1) unique2++;
        // }

        // if(unique1==1 && unique2==1) return true;

        // if(s!=goal && freq1 == freq2) return true;

        // return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        if (s.length() != goal.length())
            return false;
        int size = s.length();
        int countDiff = 0;

        for (int i = 0; i < size; i++) {

            if (s[i] != goal[i])
                countDiff++;
            freq1[s[i] - 'a']++;
            freq2[goal[i] - 'a']++;
        }

        if (freq1 != freq2)
            return false;

        if (countDiff == 2)
            return true;

        if (countDiff == 0) {
            for (int i = 0; i < 26; i++) {
                if (freq1[i] > 1)
                    return true; // Found a duplicate, valid swap
            }
        }

        return false;
    }
    
};