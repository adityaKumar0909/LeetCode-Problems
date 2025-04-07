class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long sum = 0;
        int max = INT_MIN;
        for(auto &x:milestones){
            sum+=x;
            if(x>max)max = x;
        }

         long long rem_sum=sum-max;

        if(max > rem_sum) return 1 + 2*rem_sum;
        else{
            return sum; ;
        }

        return 0;
    }
};