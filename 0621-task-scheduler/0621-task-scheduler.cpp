class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26, 0);
        int maxFreq = 0;
        int maxCount = 0;

        for (auto &x : tasks) {
            counter[x - 'A']++;
            if (maxFreq == counter[x - 'A']) {
                maxCount++;
            } else if (maxFreq < counter[x - 'A']) {
                maxFreq = counter[x - 'A'];
                maxCount = 1;
            }
        }

        int gaps = maxFreq - 1;
        int gapLength = n - (maxCount -1);
        int emptySlots = gaps * gapLength;
        int availableTasks = tasks.size() - maxFreq * maxCount;
        int idles = std::max(0, emptySlots - availableTasks);

        return tasks.size() + idles;
    }
};
