class Solution {
public:
    int minSwaps(vector<int>& nums) {

        //count total 1s
        int count = 0;
        for(auto x:nums){
            if(x==1) count++;
        }

        int minWindow = INT_MAX;


        //Count zeroes in first window
        int cnt = 0;

        for(int i=0;i<count;i++){
            if(nums[i] == 0)
            cnt++;
        }

        if(cnt<minWindow) minWindow = cnt;

        //Sldiing the window
        for(int i = 1;i<nums.size();i++){
            
            //Adding new element in window 
            int j = (i+count-1) % nums.size();
            if(nums[j]==0) cnt++;

            //Removing old element in window
            if(nums[i-1]==0) cnt--;

            if(cnt<minWindow) minWindow  = cnt;

        }

        return minWindow;

    }
};