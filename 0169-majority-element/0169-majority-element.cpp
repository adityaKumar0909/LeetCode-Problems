class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majorityEle = nums[0];

        for(int i = 1;i<nums.size();i++){
            if(nums[i] == majorityEle) count++;
            else count--;
            if(count==0){
            majorityEle = nums[i];
            count=1;
            }
        }

        return majorityEle;
        
    }
};