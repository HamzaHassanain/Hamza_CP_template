#include <bits/stdc++.h>
using namespace std;

signed main()
{

    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (auto &x : a)
        cin >> x;
    vector<long long> pref = a;
    ;
    for (int i = 1; i < n; i++)
        pref[i] += pref[i - 1];

    while (m--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << pref[r] - (l ? pref[l - 1] : 0) << "\n";
    }

    return 0;
}