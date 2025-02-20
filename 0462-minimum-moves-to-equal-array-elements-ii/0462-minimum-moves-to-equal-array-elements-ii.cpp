class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // int maximum=INT_MIN;
        // for (auto:x){
        //     if(x>maximum) maximum=x;
        // }

        // vector<int> freq
        int size = nums.size();
        sort(nums.begin(),nums.end());
        int median = nums[size/2];
        cout<<median;

        int count = 0;
        for(auto x:nums){
            count += abs(x-median);
        }
        return count;
        
        
    }
};