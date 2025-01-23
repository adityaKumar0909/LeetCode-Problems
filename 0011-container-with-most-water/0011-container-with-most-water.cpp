class Solution {
public:
    int maxArea(vector<int>& height) {

        int n = height.size();

        int i = 0;
        int j = n-1;
        int m = INT_MIN;

        while(i<j){

            int h = min(height[i],height[j]);
            int b = j-i;
            m = max(m, h*b);

            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }   
        }
        return m;
    }
};