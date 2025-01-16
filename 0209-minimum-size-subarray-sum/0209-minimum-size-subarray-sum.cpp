class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int cost = 0;
        int digit = 0;
        int minLength = INT_MAX;
        while(end<nums.size()){

            cost += nums[end];

            while(cost>=target){
             cost-=nums[start];
              minLength = min(minLength,end-start+1);
             start++;
            
            }

            // minLength = min(minLength , end - start + 1);
            //  cout<<minLength<<endl;

            end++;
       }

       return minLength==INT_MAX ? 0 : minLength;
    }
};