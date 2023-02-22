#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
using namespace std;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

bool use_clock = false;

#define nl << "\n"
#define null nullptr
#define ll long long
#define ull unsigned long long
#define of :
ll OO = 1e9;
#define no return void(cout << "NO" nl)
#define yes return void(cout << "YES" nl)
#define all(vec) vec.begin(), vec.end()
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define for1n(i, n) for (ll i = 1; i <= n; ++i)
#define forr(i, n) for (ll i = n - 1; i >= 0; --i)
#define negMod(n, m) (-n % m + m) % m
#define print(nums, n)          \
    for (ll i = 0; i < n; i++)  \
        cout << nums[i] << " "; \
    cout nl;
#define get(nums, n)           \
    for (ll i = 0; i < n; i++) \
        cin >> nums[i];
#define pt pair<ll, ll>
#define x first
#define y second
#define rv(exp) return void(cout << exp)
#define str string
void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template <typename T>
bool equals(T *a, T *b, ll n)
{
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
template <typename T>
T max(T *nums, ll n)
{
    T mx = -OO;
    for (ll i = 0; i < n; i++)
    {
        mx = max(mx, nums[i]);
    }
    return mx;
}
template <typename T>
T min(T *nums, ll n)
{
    T mn = OO;
    for (ll i = 0; i < n; i++)
    {
        mn = min(mn, nums[i]);
    }
    return mn;
}
short digit(char ch)
{
    return ch - '0';
};
ull sumall(ll x)
{
    return x * (x + 1) / 2;
}

void solve()
{
    int n;
    cin >> n;
    str s;
    cin >> s;
    int l = 0;
    int r = n - 1;
    int minDif = 26;
    while (l <= r)
    {
        int equ = abs(s[r] - s[l]);
        minDif = min(equ == 25 ? 1 : equ, minDif);
        l++, r--;
    }
    rv(minDif nl);
}
int main()
{
    auto t1 = high_resolution_clock::now();
    FastIO();
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    if (use_clock)
    {

        cout nl;
        cout << "Chrono =========================" nl;
        cout << ms_double.count() << "ms\n";
        cout << "Chrono =========================";
    }
}
