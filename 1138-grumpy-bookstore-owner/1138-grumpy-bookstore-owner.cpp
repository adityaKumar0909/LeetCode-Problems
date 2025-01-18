class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        if(minutes==1 && customers.size()==1) return customers[0];

        // vector<int> ans;

        int unsatisfiedCust = 0;
        for(int i = 0 ; i < minutes ; i++){
            unsatisfiedCust += customers[i]*grumpy[i];
        }
        int maxUnsatisfied = unsatisfiedCust;
        int index = 0;

        for(int i = minutes ; i< customers.size();i++){
            //Adding new unsatisfied customer
            unsatisfiedCust += customers[i]*grumpy[i];
            //Removing old unsatisfied customer
            unsatisfiedCust -= customers[i-minutes]*grumpy[i-minutes];
            
            if(maxUnsatisfied < unsatisfiedCust) {
                maxUnsatisfied = unsatisfiedCust;
                index = i;
            }

        }

        cout<<maxUnsatisfied<<endl;

        int maxSatisfiedLater = maxUnsatisfied;
        int satisfiedCust = 0;

        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0)
            satisfiedCust+=customers[i];
        }
        

        cout<<satisfiedCust<<endl;

        return satisfiedCust + maxSatisfiedLater;


    }
};