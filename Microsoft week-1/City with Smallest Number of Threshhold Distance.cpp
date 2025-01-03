class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for(int i=0;i<n;i++) dist[i][i]=0;
        for(vector<int> v : edges){  // edges are bidirect
            dist[v[0]][v[1]] =v[2]; //edges[i] = [fromi, toi, weighti]
            dist[v[1]][v[0]] =v[2]; //edges[i] = [fromi, toi, weighti]
        }

        for(int k=0;k<n;k++) // acts as pivot
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i !=j && dist[i][k]!=INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j ] = dist[i][k] + dist[k][j];
                }
            }
        }
        int  leastreached=INT_MAX, resCity = 0;
        for(int i=0;i<n;i++)
            {
                int reached=0; // every loop is new city
                for(int j=0;j<n;j++)
                {
                    if( i!=j && dist[i][j] <= distanceThreshold) 
                    {
                        reached++;
                    }
                }
                if(reached <= leastreached){
                    leastreached = reached;
                    resCity = i;
                }
    }
    return resCity;
    }

};