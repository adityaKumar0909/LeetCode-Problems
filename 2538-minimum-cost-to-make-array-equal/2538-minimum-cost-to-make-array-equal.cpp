class Solution {
public:

    long long findCost(int val,vector<int>& nums,vector<int>& cost){

        long long totalCost = 0;

        int size = nums.size();
        for(int i=0;i<size;i++){
            long long  diff = abs(nums[i] - val);
            totalCost += (long long)cost[i] * diff;
        }

        return totalCost;
        
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        while(start<end){

            int mid = (start+end) / 2;
            long long sum1 = findCost(mid,nums,cost);
            long long sum2 = findCost(mid+1,nums,cost);


            if(sum2<sum1){
                start   = mid+1;
                
            }

            else{
                end = mid;
            }
            
        }
       return findCost(start,nums,cost);

    }
};