class Solution {
public:
    int trap(vector<int>& height) {

        int size = height.size();
        int leftMax = 0;
        int rightMax = 0;
        int i = 0;
        int j = size-1;
        int count=0;

        while(i<j){
            if(height[i] <  height[j]){

                if(leftMax > height[i]){
                    count+=leftMax - height[i];
                }

                leftMax = max(leftMax , height[i]);

                i++;
 
            }
            else{

                if(rightMax > height[j]){
                    count+=rightMax - height[j];
                }

                rightMax = max(rightMax,height[j]);

                j--;

            }
        }

        return count;
        
    }
};