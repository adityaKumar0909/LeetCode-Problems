class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        int target = totalSum - x;
        if (target < 0) return -1; // If x is greater than the total sum, not possible.
        if (target == 0) return nums.size(); // If x equals total sum, all elements must be removed.

        int currentSum = 0, maxSubarrayLength = -1;
        int start = 0;

        for (int end = 0; end < nums.size(); end++) {
            currentSum += nums[end];

            // Shrink the window until the sum is <= target
            while (currentSum > target) {
                currentSum -= nums[start];
                start++;
            }

            // Check if we found a valid subarray with sum == target
            if (currentSum == target) {
                maxSubarrayLength = max(maxSubarrayLength, end - start + 1);
            }
        }

        // If no subarray was found, return -1
        return maxSubarrayLength == -1 ? -1 : nums.size() - maxSubarrayLength;
    }
};
