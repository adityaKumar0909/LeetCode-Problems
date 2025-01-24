class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s = 0, maxWindow = 0, unique = 0;
        vector<int> freq(fruits.size(), 0); // Frequency vector to track counts of each fruit type

        for (int e = 0; e < fruits.size(); ++e) {
            if (freq[fruits[e]] == 0) {
                unique++; // A new fruit type is encountered
            }
            freq[fruits[e]]++;

            // If there are more than 2 types of fruits, shrink the window
            while (unique > 2) {
                freq[fruits[s]]--;
                if (freq[fruits[s]] == 0) {
                    unique--; // A fruit type is completely removed
                }
                s++;
            }

            // Update the maximum window size
            maxWindow = max(maxWindow, e - s + 1);
        }

        return maxWindow;
    }
};
