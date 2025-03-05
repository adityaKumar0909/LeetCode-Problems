class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {

        //Finding all the variations of (a+b) and adding it
        //to map
        unordered_map<int,int> mpp ; 
       for (int a : nums1) {
            for (int b : nums2) {
                mpp[a + b]++;
            }
        }

        int count = 0;
        //Debugging
        // cout<<st.size();
        for (int c : nums3) {
            for (int d : nums4) {
                count += mpp[-(c + d)];  
            }
        }
         


        return count;
        
        
    }
};