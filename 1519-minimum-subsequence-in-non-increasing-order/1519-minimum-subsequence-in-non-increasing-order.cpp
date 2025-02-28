class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        
        long long  sum = 0;
        for(auto x:nums){
            sum+=x;
        }

        long long  n=nums.size();

        long long ans = 0;
        vector<int> arr;

        for(int i=n-1;i>=0;i--){
            ans+=nums[i];
            arr.push_back(nums[i]);


            long long  diff = sum - ans;
            if(ans>diff) break;
        }

        return arr;
        
    }
};