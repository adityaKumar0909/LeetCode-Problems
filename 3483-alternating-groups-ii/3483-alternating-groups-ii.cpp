class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int start = 0, count1 = 0, count2 = 0;

        for (int end = 1; end < 2 * n; end++) {
            // Check if the current and previous colors are different (using modulo for cyclicity)
            if (colors[end % n] != colors[(end - 1) % n]) {
                if (end - start + 1 >= k) {
                    count2++;
                }
            } else {
                // Reset the start index when alternation breaks
                start = end;
            }

            // Record the count of groups after one full cycle
            if (end == n - 1) {
                count1 = count2;
            }
        }

        // Return the difference between total groups and groups in one full cycle
        return count2 - count1;
    }
};
