class Solution {
public:

    bool funct(vector<int>& nums, int pairs , int diff){
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
          if((nums[i+1]-nums[i])<=diff){
             count++;
             i++;
             }
          if(count>=pairs) break;
        }

        return count>=pairs;
    }
    int minimizeMax(vector<int>& nums, int p) {

        sort(nums.begin(),nums.end());

        int n  = nums.size();
        int start = 0;
        int end = nums[n-1] - nums[0];

        int ans = end;

        while(start<=end){
            int mid = start+(end-start)/2;

            if(funct(nums,p,mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
        
        
    }
};