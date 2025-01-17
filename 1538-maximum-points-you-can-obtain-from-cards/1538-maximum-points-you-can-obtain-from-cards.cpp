class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int Score = 0;
        for(int i = 0 ; i < k ; ++i){
            Score += cardPoints[i];
        }

        int maxScore = Score;
        int n = cardPoints.size();
        for(int i = 0 ; i < k ; ++i){
            Score = Score - cardPoints[k-1-i];
            Score = Score + cardPoints[n-1-i];
           
            if(maxScore < Score){
                maxScore = Score ;
            }
        }
        return maxScore  ;
    }
};