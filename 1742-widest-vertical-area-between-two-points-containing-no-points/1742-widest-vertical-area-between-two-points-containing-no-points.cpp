class Solution {
public: 
    static bool cmp(vector<int>& a , vector<int>& b){
    return a[0]<b[0];
    }

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        
        sort(points.begin(),points.end(),cmp);
        int diff = INT_MIN;
        for(int i=0;i<points.size()-1;i++){
            diff = max(diff,points[i+1][0]-points[i][0]);
        }

        return diff;
    }
};