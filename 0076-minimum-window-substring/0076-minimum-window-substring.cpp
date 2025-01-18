class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length())
            return "";

        unordered_map<char, int> mpp1, mpp2;

        // Frequency of elements of T
        for (int i = 0; i < t.length(); i++) {
            mpp1[t[i]]++;
        }

        int count = 0;
        int minWindowSize = INT_MAX;

        int start = 0;
        int end = 0;
        int k = 0; // This will be used to store minimum window size
   
        while(end<s.length())
        {

            if (mpp1.find(s[end]) != mpp1.end()) {
                mpp2[s[end]]++;
                if (mpp2[s[end]] == mpp1[s[end]])
                    count++;
            }

            if (count == mpp1.size()) {
                while (start < s.length() &&
                       (mpp1.find(s[start]) == mpp1.end() ||
                        mpp2[s[start]] > mpp1[s[start]])) {
                    if (mpp1.find(s[start]) != mpp1.end()) {
                        mpp2[s[start]]--;
                
                    }
                    // if(start<s.length())
                    start++;
                }

                // k = ;
                // minWindowSize = min(minWindowSize, end-start+1);
                if( end - start + 1 < minWindowSize ){
                    k = start;
                    minWindowSize = end-start+1;
                }
            }

            end++;
        }
     
        // If start crosses end, no valid window exists
        if (start > end || minWindowSize ==INT_MAX) {
            return "";
        }

        return s.substr(k,minWindowSize);
 
    }
};