class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if (p.length() > s.length())
            return {};

        vector<int> mpp1(128, 0), mpp2(128, 0);

        for (auto x : p) {
            mpp1[int(x)]++;
        }

        int totalCount = 0;

        for (auto x : mpp1) {
            if (x > 0)
                totalCount++;
        }

        int start = 0;
        int end = 0;
        int count = 0;

        vector<int> ans;

        while (end < s.length()) { 
            
            //If char exist in mpp1
            if (mpp1[s[end]] >= 1) {
                mpp2[s[end]]++;

                //if freq in both maps same ( we have reached target for that specific alphabet)
                if (mpp2[s[end]] == mpp1[s[end]]) {
                    count++;
                }
            }
            
            //If window size greater than length of p
            while (end - start + 1 > p.length()) {

                //If the character exist in mpp1
                if (mpp1[s[start]] > 0) {
                    
                    //for case: cbca if you remove the first c , count wont be less 
                    if (mpp2[s[start]] == mpp1[s[start]])
                        count--;
                    //decremenet freq of that character in mpp2
                    mpp2[s[start]]--;
                }

                start++;
            }

            //If count in window reached totalcount of unique letters in p
            if (count == totalCount)
                ans.push_back(start);

            end++;
        }

        return ans;
    }
};