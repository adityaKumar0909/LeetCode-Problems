class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if (p.length() > s.length())
            return {};

        vector<int> mpp1(128, 0), mpp2(128, 0);

        for (auto x : p) {
            mpp1[int(x)]++;
            cout << "Mapping " << x << endl;
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

            if (mpp1[s[end]] >= 1) {
                mpp2[s[end]]++;

                if (mpp2[s[end]] == mpp1[s[end]]) {
                    count++;
                }
            }

            while (end - start + 1 > p.length()) {
                if (mpp1[s[start]] > 0) {
                    if (mpp2[s[start]] == mpp1[s[start]])
                        count--;

                    mpp2[s[start]]--;
                }

                start++;
            }

            if (count == totalCount)
                ans.push_back(start);

            end++;
        }

        return ans;
    }
};