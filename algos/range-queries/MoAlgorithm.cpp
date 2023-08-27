#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MOD = 1e9 + 7;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define of :
#define ll long long
#define rv(exp) return void(cout << exp << endl)
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return out;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
        cin >> v[i];
    return in;
}

const int N = 200005;
const int AMAX = 1000005;
const int Q = 200005;
const int SQ = sqrt(N) + 1;
struct query
{
    int l, r, q_idx, block_idx;
    query() {}
    query(int _l, int _r, int _q_idx)
    {
        l = _l - 1, r = _r - 1, q_idx = _q_idx, block_idx = _l / SQ;
    }
    bool operator<(const query &y) const
    {
        if (block_idx != y.block_idx)
        {
            return block_idx < y.block_idx;
        }
        return r < y.r;
    }
};
long long n, q, s[N], res = 0, q_ans[Q], f[AMAX], ff[N];
int mx = 0;
query queries[Q];
void add(int idx)
{
}
void remove(int idx)
{
}
void MO_process()
{
    sort(queries, queries + q);
    memset(f, 0, sizeof f);

    int l = queries[0].l, r = queries[0].l - 1;
    for (int i = 0; i < q; i++)
    {
        while (r < queries[i].r)
            add(++r);
        while (r > queries[i].r)
            remove(r--);
        while (l < queries[i].l)
            remove(l++);
        while (l > queries[i].l)
            add(--l);

        q_ans[queries[i].q_idx] = res;
    }
}

signed main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--; // one based
        queries[i] = query(++l, ++r, i);
    }
    MO_process();
    for (int i = 0; i < q; i++)
    {
        cout << q_ans[i] << '\n';
    }
}
