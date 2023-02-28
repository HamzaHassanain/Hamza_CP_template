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
    vector<long long> data;
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        data.assign(2 * size, 0LL); // asigin it to the cloeset poewr of two
    }
    void set(int i, long long value, int node, int beginSeg, int endSeg)
    {
        if (beginSeg == endSeg)
        {
            data[node] = value;
            return;
        }

        int mid = (beginSeg + endSeg) / 2;
        if (i <= mid)
            set(i, value, 2 * node, beginSeg, mid);
        else
            set(i, value, 2 * node + 1, mid + 1, endSeg);

        data[node] = (data[2 * node] + data[2 * node + 1]);
    }

    long long sum(int left, int right, int node, int beginSeg, int endSeg)
    {
        if (beginSeg > right || left > endSeg)
            return 0;

        if (beginSeg >= left && endSeg <= right)
            return data[node];

        int mid = (beginSeg + endSeg) / 2;
        long long sum1 = this->sum(left, right, 2 * node, beginSeg, mid);
        long long sum2 = this->sum(left, right, 2 * node + 1, mid + 1, endSeg);

        return (sum1 + sum2);
    }
    long long sum(int left, int right)
    {

        return sum(left, right, 1, 1, size);
    }
    void set(int i, long long value)
    {
        set(i, value, 1, 1, size);
    }
};

int main()
{
}