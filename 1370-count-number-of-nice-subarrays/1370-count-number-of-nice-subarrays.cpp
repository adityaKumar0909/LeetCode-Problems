class Solution {
public:
    int CountFunction(vector<int>& nums, int k) {

        int s = 0;
        int e = 0;
        int count = 0;

        while (e < nums.size()) {
          //If current element is Odd 
          if(nums[e]%2==1) k--;

          while(k<0){
            if(nums[s]%2==1) k++;
            s++;
          }

          count+=e-s+1;
          e++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {

        return CountFunction(nums,k) - CountFunction(nums,k - 1);
    }
};