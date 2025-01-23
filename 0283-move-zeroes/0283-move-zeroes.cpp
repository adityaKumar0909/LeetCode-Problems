class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int size = nums.size();
        int p = 0;
        int q = 0;
    
        while(q<size){
            //If q is a non-zero element just swap
            if(nums[q]!=0){
            swap(nums[p],nums[q]);
            p++;
            q++;
            }
            else{
            q++;
            }
        }
        
    }
};