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
            vector<int> temp;
            if (diff == minDiff) {
                temp.push_back(arr[i]);
                temp.push_back(arr[i + 1]);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};