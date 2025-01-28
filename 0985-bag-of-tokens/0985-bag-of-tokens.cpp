class Solution {
public:
    int bagOfTokensScore(vector<int>& arr, int power) {

        sort(arr.begin(), arr.end());

        int score = 0;

        int size = arr.size();
        int j = size - 1;
        int i = 0;

        while (i <= j) {

            // if element is lesser than power
            if (arr[i] <= power) {
                score++;
                power -= arr[i];
            } else {
                power += arr[j];
                score--;
                if(score < 0)
                return 0;
                j--;

                if (arr[i] <= power) {
                    score++;
                    power -= arr[i];
                }
            }

            i++;
        }

        return score;
    }
};