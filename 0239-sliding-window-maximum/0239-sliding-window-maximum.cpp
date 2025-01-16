class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {


        vector<int> ans;
 
        // if(k==1){
        //     for(auto x:arr){
        //         ans.push_back(x);
        //     }
        //     return ans;
        // }
        deque<pair<int, int>> dq;
        int index = 0;
        int max = arr[0];

        // Precomputing for first k window size
        for (int i = 0; i < k; i++) {
            if (arr[i] > max) {
                max = arr[i];
                index = i;
            }
        }

        dq.emplace_back(index, arr[index]);
        ans.push_back(arr[index]);

        for (int i = index + 1; i < k; i++) {
            while (!dq.empty() && dq.back().second < arr[i]) {
                dq.pop_back();
            }

            dq.emplace_back(i, arr[i]);
        }


        int e = k;
        int s = 1;

        while (e < arr.size()) {

            // If max element goes out of window , pop it out
            if (dq.front().first < s) {
                dq.pop_front();
            }

            // Now adding the new number
            while (!dq.empty() && dq.back().second < arr[e]) {
                dq.pop_back();
            }
            //Add the element to queue
            dq.emplace_back(e, arr[e]);
            
            //The bottom most(front) element of queue is the maximum element 
            //so store in answer vecror/ArrayListr
            if (!dq.empty())
                ans.push_back(dq.front().second);
            
            //Shift Window
            e++;
            // if(s<e)
            s++;
        }
        return ans;
    }
};