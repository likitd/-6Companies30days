//TLE
// class Solution {
// public:
//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         vector<int>dp(envelopes.size(),1);
//         sort(envelopes.begin(),envelopes.end());
//         for(int i=0;i<envelopes.size();i++){
//             for(int j=0;j<i;j++){
//                 if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) 
//                 dp[i]  = max(dp[j] +1 , dp[i]);
//             }
//         }
//         return *max_element(dp.begin(), dp.end());
//     }
// };

class Solution {
public:
static bool comp(vector<int>&a , vector<int>&b){
            if(a[0] == b[0]) return a[1]> b[1];
            return a[0] < b[0];
        }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(),envelopes.end(),comp);
        int i,j,n= envelopes.size();
        vector<int>lis;
        for(auto& env:envelopes){
            int height = env[1];
            
                auto it = lower_bound(lis.begin(), lis.end(),height);
                if(it == lis.end()){
                         lis.push_back(height);
                }else{
                        *it= height;
                }
                
            
        }
        return lis.size();
    }

};