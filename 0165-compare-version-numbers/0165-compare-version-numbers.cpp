class Solution {
public:
    int compareVersion(string version1, string version2) {

        
        int i = 0;
        int j = 0;

        for(int i=0,j=0;i<version1.length() || j<version2.length();i++,j++){

        int v1=0;
        int v2=0;

        //Calculate values till we find a dot
        while(i<version1.length() && version1[i]!='.'){
            v1 = v1*10 + ( version1[i] - '0');
            i++;
        }

        //Calculate values till we get a dot
         while(j<version2.length() && version2[j]!='.'){
            v2 = v2*10 + ( version2[j] - '0');
            j++;
        }

        //Comparing v2 and v1
        if(v2>v1) return -1;
        else if(v1>v2) return 1;
    
 
        }

        return 0;
        
    }
};