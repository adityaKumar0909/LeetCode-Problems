class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Answer vector
        vector<vector<int>> ans;

        // Sorterd the nums vector
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            //If duplicate elements skip
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            //Target of simplified 2Sum problem
            int target = -1 * (nums[i]);
            //Left most element 
            int l = i + 1;
            //Right most element
            int r = nums.size() - 1;

            while (l < r) {

                int sum = nums[l] + nums[r];

                if (sum == target) {
                    //Add into answer vector
                    vector<int> temp = {nums[r], nums[l], nums[i]};
                    // Move left and right pointers  when duplicates are encountered
                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                    ans.push_back(temp);
                }

                else if (sum > target) {
                    r--;
                }

                else {
                    l++;
                }
            }
        }

        return ans;
    }
};