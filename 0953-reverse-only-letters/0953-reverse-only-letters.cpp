class Solution {
public:
    string reverseOnlyLetters(string s) {

        int start = 0;
        int size = s.length();
        int end = size-1;

        while(start<end){
            if(!isalpha(s[start]) && start<size) start++;
            if(!isalpha(s[end]) && end>=0 ) end--;
            else{
            if(isalpha(s[start]) && isalpha(s[end])){
            swap(s[start],s[end]);
            start++;
            end--;
            }
            }

        }

        return s;
        
    }
};