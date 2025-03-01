class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());  
        int minDiff = INT_MAX;

        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];  
            
            if (diff < minDiff) {
                minDiff = diff;
                ans.clear();  
            }
            if (diff == minDiff) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return ans;
    }
};
