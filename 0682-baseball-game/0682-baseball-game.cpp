#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> arr;
        int sum = 0;

        for (const string& str : operations) {
            if (str == "C") {
                if (!arr.empty()) {
                    arr.pop_back();
                }
            } 
            else if (str == "D") {
                if (!arr.empty()) {
                    arr.push_back(2 * arr.back());
                }
            } 
            else if (str == "+") {
                if (arr.size() >= 2) {
                    arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
                }
            } 
            else {
                int num = stoi(str);
                arr.push_back(num);
            }
        }

        for (int x : arr) {
            sum += x;
        }

        return sum;
    }
};


