class Solution {
public:

    vector<long> countSort(vector<int>&costs,int range){
        vector<long> arr(range+1,0);
        for(auto x:costs){
            arr[x]++;
        }

        vector<long> ans;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>0){
                for(int j=0;j<arr[i];j++){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
    int maxIceCream(vector<int>& costs, int coins) {
        int maximum=INT_MIN;
        for(auto x:costs) maximum = max(maximum,x);

        vector<long> newArr = countSort(costs,maximum);
        int count = 0;
        int n=newArr.size();
        for(int i=0;i<n;i++){
            coins -= newArr[i];
            if(coins>=0) count++;
            if(coins<0) break;
        }

        return count;
        
    }
};