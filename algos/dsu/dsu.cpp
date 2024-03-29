template <typename T = int, int Base = 1>
struct DSU
{

    vector<T> parent, Gsize;

    DSU(int MaxNodes)
    {
        parent = Gsize = vector<T>(MaxNodes + 5);
        for (int i = Base; i <= MaxNodes; i++)
            parent[i] = i, Gsize[i] = 1;
    }

    T find_leader(int node)
    {
        return parent[node] = (parent[node] == node ? node : find_leader(parent[node]));
    }

    bool is_same_sets(int u, int v)
    {
        return find_leader(u) == find_leader(v);
    }

    void union_sets(int u, int v)
    {
        int leader_u = find_leader(u), leader_v = find_leader(v);
        if (leader_u == leader_v)
            return;
        if (Gsize[leader_u] < Gsize[leader_v])
            swap(leader_u, leader_v);
        Gsize[leader_u] += Gsize[leader_v], parent[leader_v] = leader_u;
    }

    int get_size(int u)
    {
        return Gsize[find_leader(u)];
    }
};
