class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool isOneFound = false;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) isOneFound = true;
            if (nums[i] <= 0 || nums[i] > n)
             nums[i] = 1;
        }
        if (!isOneFound) return 1;

        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;  
            if (index < n && nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;
    }
};
