void make_set(big node, vector<big> &par, vector<big> &size)
{
    par[node] = node;
    size[node] = 1;
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

void union_by_size(big a, big b, vector<big> &par, vector<big> &size)
{
    a = find_set(a, par);
    b = find_set(b, par);

    if (a != b)
    {
        if (size[a] < size[b])
        {
            swap(a, b);
        }
        par[b] = a;
        size[a] += size[b];
    }
}