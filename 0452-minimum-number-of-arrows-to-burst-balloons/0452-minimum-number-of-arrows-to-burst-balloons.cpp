class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int findMinArrowShots(vector<vector<int>>& points) {

        sort(points.begin(), points.end(), cmp);

        int intEnd = points[0][1];
        int count = 1;
        int size = points.size();
        for (int i = 1; i < size; i++) {

            if (intEnd < points[i][0]) {
                count++;
                intEnd = points[i][1];
            }
        }

        return count;
    }
};