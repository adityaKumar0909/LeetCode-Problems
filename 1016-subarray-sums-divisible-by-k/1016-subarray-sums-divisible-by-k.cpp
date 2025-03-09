class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum =  0 ;
        unordered_map<int,int> map;
        map[0] = 1;
        int rem = 0;
        
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            rem = sum%k;
            if(rem<0) rem+=k;
           
            count+=map[rem];
        

            map[rem]++;

        }

        return count;


        
    }
};