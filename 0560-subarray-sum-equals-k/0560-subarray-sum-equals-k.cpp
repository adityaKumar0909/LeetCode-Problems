class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int prefix[n];

        prefix[0] = nums[0];

        //Fill the prefix array
        for(int i =1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i]; 
        }
       //Declare a map
        unordered_map<int,int> mp;

        int count = 0;

        for(int i = 0;i<n;i++){
            if(prefix[i]==k)
            count++;
          
            if(mp.find(prefix[i]-k)!=mp.end()){
            count+=mp[prefix[i]-k];
            // count++;
            }

            mp[prefix[i]]++;
        }

        return count;

        
    }
};