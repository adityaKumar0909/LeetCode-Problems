class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        

        int count  = 0;
        int i = 0;
        int j;

        for(j=0;j<nums.size()-1;j++){

            if(nums[j] != nums[j+1]){
                nums[i] = nums[j];
                i++;
            }

        }

         
                nums[i] = nums[j];
                i++;
            


        return i;
    }
};