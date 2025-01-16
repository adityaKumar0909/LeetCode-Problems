class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int> ans;
        
        deque<pair<int, int>> dq;

        int e = 0;
        int s = 0;

        while (e < arr.size())
         {

            // Now adding the new number
            while (!dq.empty() && dq.back().second < arr[e]) {
                dq.pop_back();
            }
            //Add the element to queue
            dq.emplace_back(e, arr[e]);

            // If max element goes out of window , pop it out
            if (dq.front().first < s ) {
                dq.pop_front();
            }
            
            //This check wont increase value of S till we get a size of k ( window size)
            //Dry run
            /*

            Suppose window size is 3
            Iter 1: s=0 ,e=0
            Iter 2: s=0 ,e=1
            Iter 3: s=0 ,e=2
            Iter 4: s=0 ,e=2

            now that window size is 3 
            Window will shift

            */

            if (e-s+1==k){
                ans.push_back(dq.front().second);
                s++;
            }
            
            //Shift Window
            e++;

        }
        return ans;
    }
};