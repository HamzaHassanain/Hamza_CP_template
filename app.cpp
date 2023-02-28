#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
using namespace std;
// collapse
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

bool global_use_clock = false;
#define use_clock global_use_clock = true;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
typedef vector<ull> vecull;
typedef vector<pair<ll, ll>> vecp;
typedef vector<vector<ll>> vecv;
typedef vector<set<ll>> vecset;
typedef vector<string> vecstr;
typedef pair<ll, ll> pl;
ll OO = 1e9;

#define sz(cont) size(cont)
#define of :
#define nl << "\n"
#define null nullptr
#define no return void(cout << "NO" nl)
#define yes return void(cout << "YES" nl)
#define all(vec) vec.begin(), vec.end()
#define allrev(vec) vec.rbegin(), vec.rend()
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define for1n(i, n) for (ll i = 1; i <= n; ++i)
#define forr(i, n) for (ll i = n - 1; i >= 0; --i)
#define negMod(n, m) (n % m + m) % m
#define print(nums)                     \
    for (ll i = 0; i < size(nums); i++) \
        cout << nums[i] << " ";         \
    cout nl;

#define printv(nums)                           \
    for (ll i = 0; i < size(nums); i++)        \
    {                                          \
        for (ll j = 0; j < size(nums[i]); j++) \
            cout << nums[i][j] << " ";         \
        cout nl;                               \
    }

#define printp(nums)                    \
    for (ll i = 0; i < size(nums); i++) \
        cout                            \
            << nums[i].first << ":" << nums[i].second nl;

#define get(nums)                       \
    for (ll i = 0; i < size(nums); i++) \
        cin >> nums[i];
#define getp(nums)                      \
    for (ll i = 0; i < size(nums); i++) \
        cin >> nums[i].first >> nums[i].second;
#define sep cout << "===================================" << endl;
#define rv(exp) return void(cout << exp)
#define str string
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>

void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

bool equals(vector<ll> &a, vector<ll> &b)
{
    int n = size(a);
    for (ll i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}
ll max(vector<ll> &nums)
{
    int n = size(nums);
    ll mx = -OO;
    for (ll i = 0; i < n; i++)
    {
        mx = max(mx, nums[i]);
    }
    return mx;
}
ll min(vector<ll> &nums)
{
    int n = size(nums);
    ll mn = OO;
    for (ll i = 0; i < n; i++)
    {
        mn = min(mn, nums[i]);
    }
    return mn;
}
ll max(vector<ll> &nums, int beg, int end)
{
    int n = end;
    ll mx = -OO;
    for (ll i = beg; i < n; i++)
    {
        mx = max(mx, nums[i]);
    }
    return mx;
}
ll min(vector<ll> &nums, int beg, int end)
{
    int n = end;
    ll mn = OO;
    for (ll i = beg; i < n; i++)
    {
        mn = min(mn, nums[i]);
    }
    return mn;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll gcdAll(vector<ll> &nums, int from = 0)
{
    ll n = sz(nums);
    ll cur = nums[from];
    for (ll i = from + 1; i < n; i++)
    {
        cur = gcd(cur, nums[i]);
    }
    return cur;
}
bool all_equal(vector<ll> &nums, int from = 0)
{
    int n = sz(nums);
    ll cur = nums[from];
    for (ll i = from + 1; i < n; i++)
    {
        if (cur != nums[i])
            return false;
    }
    return true;
}
short digit(char ch)
{
    return ch - '0';
};
ull sigma(ull x)
{
    return x * (x + 1) / 2;
}
ll sum_num(ll n)
{
    ll sum = 0;
    while (n > 0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
ull custom_pow(ull a, ull b)
{
    ull res = 1;
    while (b--)
        res *= a;

    return res;
}
ll custom_log(ll a, ll b)
{
    return log2(a) / log2(b);
}
// collapse
/*
 * don't be lazy in thinking
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down
 * Think of different views of the problem. don't look from only one side
 */

void test_case()
{
    ll n, m, k;
    cin >> n >> m >> k;
    vec nums(n);
    get(nums);
    ll res = 0;
    forn(i, n)
    {
        if (!m)
        {
            if (!nums[i] || !k)
                res++;
        }
        else
        {
            if (!k || !nums[i])
                continue;
            if (m % nums[i] == 0 && k == m / nums[i])
                res++;
        }
    }
    rv(res nl);
}
int main()
{
    auto t1 = high_resolution_clock::now();
    FastIO();
    ll tc = 1;
    cin >> tc;
    while (tc--)
        test_case();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    if (global_use_clock)
    {

        cout nl;
        cout << "Chrono =========================" nl;
        cout << ms_double.count() << "ms\n";
        cout << "Chrono =========================";
    }
}