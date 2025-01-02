class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>>dir={
            {-1,-1} , {-1,0} , {-1,1},
            {0,-1}, {0,0},{0,1},
            {1,-1}, {1,0}, {1,1}
        };
        int m=img.size();
        int n= img[0].size();
        vector<vector<int>> res(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int sumAvg=0,countNeighbor=0;
                    for(auto &it : dir){
                        int i_ = i + it[0];
                        int j_ = j+ it[1];

                        if(i_ >= 0 && i_ <m && j_>=0 && j_<n){ // checking if outof biund
                            countNeighbor++;
                            sumAvg +=   img[i_][j_];
                        }
                    }
                        res[i][j] = sumAvg/countNeighbor; // we are storing res in new we are not overritng and consider it for next
                    }
                
            }
        
        return res;
    }
};