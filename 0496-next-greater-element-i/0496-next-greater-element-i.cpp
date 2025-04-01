class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums1.size(); i++) {
            mpp[nums1[i]] = i;
        }
        
        vector<int> ans(nums1.size(), -1);
        stack<int> stk;
        unordered_map<int, int> nextGreater;
        
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }
            
            nextGreater[nums2[i]] = stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = nextGreater[nums1[i]];
        }
        
        return ans;
    }
};
