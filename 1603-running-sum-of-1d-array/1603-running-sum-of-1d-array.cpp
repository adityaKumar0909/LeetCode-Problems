class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> arr(nums.size(),0);
        int n = nums.size();
        arr[0] = nums[0];
        for(int i=1;i<n;i++){
            arr[i] = nums[i]+arr[i-1];
        }
        return arr;
        
    }
};