class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        //Make map for storing frequency of each 
        //element of array 1
        unordered_map<int,int> mp;

        for(auto x:nums1){
            mp[x]++;
        }
       
        vector<int> ans;
        for(int i=0;i<nums2.size();i++){
            if(mp.find(nums2[i])!=mp.end() && mp[nums2[i]]>0){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }

        return ans;





        
    }
};