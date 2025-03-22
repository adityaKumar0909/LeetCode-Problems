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

        // vector<int> prefix(nums.size(),0);
        // prefix[0] = cost[0];
        // int sum = 0;
        // for(auto x:cost){
        //     sum+=x;
        // }

        // int median = sum/2;

        // int minEle = INT_MAX;
        // int maxEle = INT_MIN;

        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]<minEle) minEle = nums[i];
        //     if(nums[i]>maxEle) maxEle = nums[i];
        //     if(i!=0){
        //         prefix[i] = prefix[i-1] + cost[i];
        //     }

        // }

        

        // for(int i=0;i<prefix.size()-1;i++){
        //     if(prefix[i] < median && median<prefix[i+1]) {
        //         median = nums[i+1];
        //         break;
        //     }
        // }


        int start = 1;
        int end = 1e6;

        while(start<=end){

            int mid = (start+end) / 2;
            long long sum1 = findCost(mid,nums,cost);
            long long sum2 = findCost(mid-1,nums,cost);
            long long sum3 = findCost(mid+1,nums,cost);

            if(sum2>= sum1 && sum1 <= sum3) return sum1;

            if(sum2<sum1){
                end   = mid;
                continue;
            }

            if(sum3<sum1){
                start = mid;
                continue;
            }
            
        }
       return 0;

    }
};