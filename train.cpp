#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define all(v) v.begin(), v.end()
#define int long long

template <typename T>
ostream &operator<<(ostream &os, vector<T> v)
{
    for (auto i : v)
        os << i << " ";
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (auto &i : v)
        is >> i;
    return is;
}

void test_case()
{
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    if (filesystem::exists("hamza_local"))
        freopen("input.in", "r", stdin), freopen("output.out", "w", stdout);

    int ts = 1;

    cin >> ts;

    while (ts--)
        test_case();

    return 0;
}