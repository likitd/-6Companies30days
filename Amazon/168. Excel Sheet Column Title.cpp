class Solution {
public:
    string convertToTitle(int columnNumber) {
        //YZ = 25*(26^1) + 26*(26^0)
        //XYZ = 24*(26^2) + 25*(26^1) + 26*(26^0)
        string ans="";
        while(columnNumber){
            ans+=((columnNumber-1)%26+'A');
            columnNumber=(columnNumber-1)/26;

        }
        reverse(ans.begin(),ans.end());
        return ans;
        
       

        
    }
};