class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        // For storign answer
        vector<vector<int>> ans;

        int minDiff = INT_MAX;
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);
            minDiff = min(diff, minDiff);
        }


        for (int i = 0; i < n - 1; i++) {
            int diff = abs(arr[i + 1] - arr[i]);
            if (diff == minDiff) {
                ans.push_back({arr[i],arr[i + 1]});
            }
        }

        return ans;
    }
};