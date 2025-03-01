class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int count=1;
        int idx=0;
        if(n==1) return count;
        for(int i = 1;i<n;i++){
            if(intervals[i][0]==intervals[idx][0]) count--;
            if(intervals[i][1]>intervals[idx][1]) {
                count++;
                idx=i;
                }

        }
         
        return count;
        
    }
};