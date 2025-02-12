class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int size = nums.size();


        int p = 0;
        int fast = 1;
        int slow = size - 1;

        vector<int> arr(size,0);

        int counter = 1;

        arr[0] = nums[0];

        for(int i=1;i<nums.size();i++){
            //same character
            if(nums[i]==nums[i-1]){
                counter++;
            }
            else{
                counter = 1;
            }

            if(counter<=2){
                arr[fast] = nums[i];
                fast++;
            }
            else if(counter>2){
                arr[slow] = nums[i];
                slow--;
            }

        }

        nums = arr;



        return fast;
        
    }
};