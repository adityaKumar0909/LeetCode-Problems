class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {


        vector<int> ans;
 
       
        deque<pair<int, int>> dq;
        // int index = 0;
        // int max = arr[0];

        // // Precomputing for first k window size
        // for (int i = 0; i < k; i++) {
        //     if (arr[i] > max) {
        //         max = arr[i];
        //         index = i;
        //     }
        // }

        // dq.emplace_back(index, arr[index]);
        // ans.push_back(arr[index]);

        // for (int i = index + 1; i < k; i++) {
        //     while (!dq.empty() && dq.back().second < arr[i]) {
        //         dq.pop_back();
        //     }

        //     dq.emplace_back(i, arr[i]);
        // }


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
            
            //The bottom most(front) element of queue is the maximum element 
            //so store in answer vecror/ArrayListr
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