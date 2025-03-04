class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        int size1 = nums1.size();
        for(int i=0;i<size1;i++){
            if(mp[nums1[i]]!=1)
            mp[nums1[i]]++;
        }


        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end() && mp[nums2[i]]>=0 ){
                ans.push_back(nums2[i]);
                mp[nums2[i]]=-1;
            }
        }

        return ans;
        
    }
};