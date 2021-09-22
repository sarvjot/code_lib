void make_set(big node, vector<big> &par, vector<big> &depth)
{
    par[node] = node;
    depth[node] = 1;
}

big find_set(big node, vector<big> &par)
{
    if (par[node] == node)
    {
        return node;
    }
    else
    {
        return par[node] = find_set(par[node], par);
    }
}

void union_by_depth(big a, big b, vector<big> &par, vector<big> &depth)
{
    a = find_set(a, par);
    b = find_set(b, par);

    if (a != b)
    {
        if (depth[a] < depth[b])
        {
            swap(a, b);
        }
        par[b] = a;
        if (depth[a] == depth[b])
        {
            depth[a]++;
        }
    }
}