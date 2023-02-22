#include <bits/stdc++.h>

using namespace std;
void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
struct segTree
{
    int size;
    vector<long long> sums;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sums.assign(2 * size, 0LL); // asigin it to the cloeset poewr of two
    }
    void set(int i, long long value, int node, int beginSeg, int endSeg)
    {
        if (endSeg - beginSeg == 1)
        {
            sums[node] = value;
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        if (i < mid)
            set(i, value, 2 * node + 1, beginSeg, mid);
        else
            set(i, value, 2 * node + 2, mid, endSeg);

        sums[node] = sums[2 * node + 1] + sums[2 * node + 2];
    }

    void set(int i, long long value)
    {
        set(i, value, 0, 0, size);
    }
    long long sum(int left, int right, int node, int beginSeg, int endSeg)
    {
        if (beginSeg >= right || left >= endSeg)
            return 0;

        if (beginSeg >= left && endSeg <= right)
            return sums[node];

        int mid = (beginSeg + endSeg) / 2;
        long long sum1 = sum(left, right, 2 * node + 1, beginSeg, mid);
        long long sum2 = sum(left, right, 2 * node + 2, mid, endSeg);

        return sum1 + sum2;
    }
    long long sum(int left, int right)
    {
        // for (int x : sums)
        // {
        //     cout << x << " ";
        // }
        // cout << endl;
        return sum(left, right, 0, 0, size);
    }
};
int main()
{
    FastIO();
    int n, q;
    cin >> n >> q;
    segTree sgt;
    sgt.init(n);

    for (int i = 0; i < n; i++)
    {
        long long value;
        cin >> value;
        sgt.set(i, value);
    }
    while (q--)
    {
        int com;
        cin >> com;
        if (com == 1)
        {
            int i, value;
            cin >> i >> value;
            sgt.set(i, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << sgt.sum(l, r) << "\n";
        }
    }
}