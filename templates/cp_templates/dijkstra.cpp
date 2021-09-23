void dijkstra(big src, big n, vector<big>& dist, vector<big>& par, vector<vector<pair<big, big>>>& adj)
{
    dist.assign(n, inf);
    par.assign(n, -1);
    dist[src] = 0;

    priority_queue<pair<big, big>, vector<pair<big, big>>, greater<pair<big, big>>> pq;
    pq.push({ 0, src });

    while (!pq.empty()) {
        pair<big, big> node = pq.top();
        pq.pop();

        big dv = node.first;
        big v = node.second;

        if (dv != dist[v]) {
            continue;
        }

        for (auto nebr : adj[v]) {
            big to = nebr.first;
            big wt = nebr.second;

            big nd = dist[v] + wt;
            if (nd < dist[to]) {
                dist[to] = nd;
                par[to] = v;
                pq.push({ nd, to });
            }
        }
    }
}