class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {

        int sum = 0;
        int s = 0;
        int e = 0;

        vector<int> mpp(1e4+1,0);

        int maxSum = INT_MIN;
        while(e<nums.size()){
            //If current number exists in window
            if(mpp[nums[e]]>0){
                maxSum = max(maxSum,sum);
               
            }
            sum+=nums[e];
            mpp[nums[e]]++;


            while(mpp[nums[e]]>1){
                sum-=nums[s];
                mpp[nums[s]]--;
                s++;
            }


       
            e++;

        }

        return maxSum>sum ? maxSum : sum;;


        
    }
};