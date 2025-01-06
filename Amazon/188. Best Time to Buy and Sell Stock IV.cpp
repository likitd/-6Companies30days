class Solution {
private: 
    int solveTab(vector<int> &prices,int k)
    {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int> (2*k+1,0));


        for(int index=n-1;index>=0;index--)
        {
            for(int opnum=0;opnum<2*k;opnum++)
            {
                int profit=0;

                if(opnum%2==0)
                    {
                       //buy allowed
                       int buykaro=-prices[index]+dp[index+1][opnum+1];
                       int skipkaro=0+dp[index+1][opnum];
                       profit=max(buykaro,skipkaro);            
                    }else
                    {
                       //sell allowed
                       int sellkaro=+prices[index]+dp[index+1][opnum+1];
                       int ignorekaro=0+dp[index+1][opnum];
                       profit=max(sellkaro,ignorekaro);            
                    }
                       dp[index][opnum]=profit;
            }
        }

        return dp[0][0];
    }

public:
    int maxProfit(int k, vector<int>& prices) {
         return solveTab(prices,k);
    }
};