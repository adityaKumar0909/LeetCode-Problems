class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       int maxPair = INT_MIN;
       int n=nums.size();
       for(int i=0;i<n;i++){
        int sum = nums[i] + nums[n-1-i];
        maxPair = max(sum,maxPair);
       }

       return maxPair;
    }
};