class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int Unsatisfied = 0;
        for(int i = 0 ; i < minutes; i++){
            Unsatisfied += customers[i]*grumpy[i];
        }

        int maxUnsatisfied = Unsatisfied;
        int index=0;

        for(int i = minutes ; i < customers.size() ; i++){
            //Adding new unsatisfied customer
            Unsatisfied += customers[i]*grumpy[i];
            //Removing old unsatisfied customer
            Unsatisfied -= customers[i-minutes]*grumpy[i-minutes];

            if(maxUnsatisfied < Unsatisfied){
                maxUnsatisfied = Unsatisfied ;
                index = i;
            }
        }

        int maxSatisfied = maxUnsatisfied;
        int totalSatisfied = 0;
        for(int i = 0 ; i < customers.size(); i++){
            if(grumpy[i] == 0){
                totalSatisfied += customers[i];
            }
        }
        return maxSatisfied + totalSatisfied;

    }
};