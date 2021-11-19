big lca(big a, big b, big lim, vector<big> &depth, vector<vector<big>> &up){
    // bringing a and b at same level

    if(depth[a] > depth[b]){
        swap(a, b);
    }
    big d = depth[b] - depth[a];

    for(big j = 0; j < lim && a != -1; j++)
    {
        if(((1 << j) & d) != 0){
            b = up[b][j];
        }
    }

    dv(a, b);
    if(a == b){
        return a + 1;
    }

    // now binary searching for level just lower than LCA

    for (big j = lim - 1; j >= 0; j--)
    {
        if(up[a][j] != up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }

    return up[a][0] + 1;
}
