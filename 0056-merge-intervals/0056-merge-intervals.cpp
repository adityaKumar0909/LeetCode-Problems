class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int size = intervals.size();
        
        vector<vector<int>> ans;
        
        int i = 0;
        int j = 1;
        int end = intervals[i][1];

        while(j<=size){

            if(j == size || end < intervals[j][0]){
                ans.push_back({intervals[i][0],end});
                i=j;
            }
            if(j != size){
                end = max(end,intervals[j][1]);
            }
            j++;
        }
        return ans;
    }
};