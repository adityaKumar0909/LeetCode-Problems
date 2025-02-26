class Solution {
public:
    string reverseVowels(string s) {

        int n = s.length();
        int i=0;
        int j=n-1;
        string vowel = "aAeEiIoOuU";
        while(i<j){

            while(i<j && vowel.find(s[i])==string::npos){
                i++;
            }

            

            while(i<j && vowel.find(s[j])==string::npos){
                j--;
            }
            
            if(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
            }

        }

        return s;
        
    }
};