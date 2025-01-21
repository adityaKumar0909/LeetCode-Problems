class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        //for storing frequency of each char in s1
        vector<int> freq(128, 0);
        //for storing frequency of each char in s2
        vector<int> freq2(128, 0);
        
        //Find unique characters in s1
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

            //If char exist in s1 , increase it's freq in s2
            if (freq[s2[end]] > 0) {

                freq2[s2[end]]++;
                
                //if freq of char in s1 and s2 matches increment count
                if (freq2[s2[end]] == freq[s2[end]])
                    count++;

            }

            // Remove old elements
            
            //If window size greater s1 length

            if (end - start + 1 > s1.length()) {
                
                //If char existed in s1 , decrease it's freq
                if (freq[s2[start]] > 0) {
                    //If freq of s1 and s2 are same 
                    if (freq[s2[start]] == freq2[s2[start]])
                        count--;
                freq2[s2[start]]--;

                }

                start++;
            }
            
            //If we have reached our goal return true
            if (count == uniqueChar) {
                return true;
            }

            end++;
        }

        return false;
    }
};