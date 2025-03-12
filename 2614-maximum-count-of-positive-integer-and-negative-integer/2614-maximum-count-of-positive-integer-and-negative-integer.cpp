class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < 0)
                start = mid + 1;  
            else
                end = mid - 1;  
        }
        int countNegatives = start;  

        start = 0;
        end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= 0)
                start = mid + 1;  
            else
                end = mid - 1;  
        }
        int countPositives = n - start;  

        return max(countNegatives, countPositives);
    }
};
