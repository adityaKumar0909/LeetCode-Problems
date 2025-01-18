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
        int l = 0;

        // Traverse the whole of S and find frequency of each letter in T
        // for (int i = 0; i < s.length(); i++) 
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

        // cout<<"Value of start : "<<start<<endl;
        // cout<<"Value of k : "<<k<<endl;
        // cout<<"Value of end : "<<end<<endl;




        // cout<<minWindowSize<<endl;

        // int start = 0;
        // while (start < s.length() && (mpp1.find(s[start]) == mpp1.end() ||
        //                               mpp2[s[start]] > mpp1[s[start]])) {
        //     if (mpp1.find(s[start]) != mpp1.end()) {
        //         mpp2[s[start]]--;
        //     }
        //     // if(start<s.length())
        //     start++;
        // }

        // int end = s.length() - 1;
        // while (end >= 0 && (mpp1.find(s[end]) == mpp1.end() || mpp2[s[end]] >
        // mpp1[s[end]])) {
        //     if (mpp1.find(s[end]) != mpp1.end()) {
        //         mpp2[s[end]]--;
        //     }
        //     end--;
        // }

        // If start crosses end, no valid window exists
        if (start > end || minWindowSize ==INT_MAX) {
            return "";
        }

        // string ans = "";
        // for (int i = start; i <= k; i++) {
        //     ans += s[i];
        // }

        return s.substr(k,minWindowSize);

        // for (auto x : mpp2) {
        //     cout << x.first << " : " << x.second << endl;
        // }

        // return ans;

        // cout << start << endl;
    }
};