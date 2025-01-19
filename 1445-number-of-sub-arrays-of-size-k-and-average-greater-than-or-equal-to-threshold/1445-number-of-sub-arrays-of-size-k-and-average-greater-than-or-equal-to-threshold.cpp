class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int sum = 0;

        //Counting avg of first k elements

        for(int i=0;i<k;i++){
            sum+=arr[i];
        }

        int count = 0;

        if(sum/k >= threshold) count++;

        //Now calculating avg of rest of the window
        for(int i=k;i<arr.size();i++){
            sum+=arr[i];
            sum-=arr[i-k];
            int avg = sum/k;

            if(avg >= threshold) count++;
        }

        return count;

        
    }
};