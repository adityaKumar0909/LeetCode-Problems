class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {

        sort(arr.begin(),arr.end());

        int i=0;
        int size = arr.size();
        int j = size-1;

        int count=0;

        while(i<=j){
            if(arr[i] + arr[j] > limit ){
                count++;
                j--;
            }
            else if(arr[i] + arr[j] <= limit) {
                count++;
                i++;
                j--;
            }
            else{
                count++;
                i++;
            }
        }

        return count;


        
    }
};