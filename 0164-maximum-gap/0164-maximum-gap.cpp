class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int gap = 0;
        
        // If the input array is empty or has less than two elements, return 0 since no gap can be formed
        if (nums.size() == 0) {
            return 0;
        }

        // Sort the array in ascending order
        sort(nums.begin(), nums.end());
        
        // Get the size of the sorted array
        int n = nums.size();
        
        // Iterate through the sorted array to find the maximum gap
        for (int i = 0; i < n - 1; i++) {
            // Calculate the difference between consecutive elements
            int sub = nums[i + 1] - nums[i];
            
            // Update the maximum gap if a larger gap is found
            if (sub > gap) {
                gap = sub;
            }
        }
        
        // Return the largest gap found between consecutive elements
        return gap;
    }
};