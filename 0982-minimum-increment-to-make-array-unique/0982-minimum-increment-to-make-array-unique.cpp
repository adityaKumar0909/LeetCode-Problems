class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int max = INT_MIN;
        for(auto x:nums){
            if(x>max){
                max  = x;
            }
        }

        int size = nums.size();

        vector<int> arr(max+size,0);


        for(int i=0;i<nums.size();i++){
            arr[nums[i]]++;
        }

        int count = 0;

        for(int i=0;i<arr.size();i++){
            int extra = arr[i] > 1 ?arr[i]-1 : 0;
            // cout<<"Extra at :"<<extra<<endl;

            count += extra;

            arr[i] -= extra;
            if(i+1!=arr.size())
            arr[i+1]+= extra;
            
        }

        return count;

    }
};