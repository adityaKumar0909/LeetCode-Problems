class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        int size = nums.size();

        for(int i=0;i<size;i++){
            sum += nums[i];
            if(sum==k){
                count++;
            }
            if(mpp.find(sum-k) != mpp.end()){
                count+=mpp[sum-k];
            }
            
            mpp[sum]++;
        }

        return count;

    }
};