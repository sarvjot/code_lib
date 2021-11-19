void bin_lift(big n, big lim, vector<vector<big>> &up, vector<big> &par){
    for(big i = 0; i < n; i++)
    {
        up[i][0] = par[i];    
    }

    for(big j = 1; j < lim; j++)
    {
        for(big i = 0; i < n; i++)
        {
            if(up[i][j - 1] == -1){
                up[i][j] = -1;
            }else{
                up[i][j] = up[up[i][j - 1]][j - 1];
            }
        }
    }
}
