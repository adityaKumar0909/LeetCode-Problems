class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;
        //Sum of whole array is lesser then required number so obvio not possible
        if (target < 0) return -1; 
        //Sum of whole array is equal to required number so just return size of whole array 
        if (target == 0) return nums.size(); 

        int Sum = 0, maxWindow = -1;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            Sum += nums[end];

            //If current Sum is greater , shrink from left side of window
            while (Sum > target) {
                Sum -= nums[start];
                start++;
            }

            // if current sum is equal , calculate window size
            if (Sum == target) {
                maxWindow = max(maxWindow, end - start + 1);
            }
        }

        // If no subarray was found return -1 and if found return (totalelements - length of window)
        return maxWindow == -1 ? -1 : nums.size() - maxWindow;
    }
};
