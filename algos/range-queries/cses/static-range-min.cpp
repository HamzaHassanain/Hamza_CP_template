#include <bits/stdc++.h>
using namespace std;

struct SparseTable
{
    vector<vector<int>> st;
    vector<int> logs;
    SparseTable(vector<int> &a)
    {
        int n = a.size();
        logs.resize(n + 1);
        logs[1] = 0;
        for (int i = 2; i <= n; i++)
            logs[i] = logs[i / 2] + 1;
        st.resize(n, vector<int>(logs[n] + 1));
        for (int i = 0; i < n; i++)
            st[i][0] = a[i];
        for (int j = 1; j <= logs[n]; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    int query(int l, int r)
    {
        int j = logs[r - l + 1];
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
signed main()
{

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    SparseTable st(a);
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << st.query(l, r) << "\n";
    }
    return 0;
}