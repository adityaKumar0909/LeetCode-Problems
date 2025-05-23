class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIndex = nums.size()-1;
        int maxIndexYouCanReachFromThisPoint = 0;
        int maxIndexYouCanReach = 0;
        int size = nums.size();

        if(size==1) return true;


        for(int i=0;i<size;i++){

            int maxIndexYouCanReachFromThisPoint = nums[i] + i;
            //Can't move forward
            // if(maxIndexYouCanReachFromThisPoint == i) return false;
            
            //Overall max you can reach till this point or from any previous point
            maxIndexYouCanReach = max(maxIndexYouCanReachFromThisPoint , maxIndexYouCanReach );

            if(maxIndexYouCanReach >= lastIndex) return true;

            if(maxIndexYouCanReach < i+1) return false;

        }

        return true;
    }
};