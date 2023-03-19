
#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
using namespace std;

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

bool use_clock = false;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
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
#define negMod(n, m) (-n % m + m) % m
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
            << nums[i].x << " " << nums[i].y nl;

#define get(nums)                       \
    for (ll i = 0; i < size(nums); i++) \
        cin >> nums[i];

#define x first
#define y second
#define rv(exp) return void(cout << exp)
#define str string

const ull N = 1e6 + 5;
bool prime[N];
void sieve()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    prime[0] = false;
    for (int p = 2; p * p < N; p++)
    {
        if (prime[p] == true)
        {

            for (int i = p * p; i < N; i += p)
                prime[i] = false;
        }
    }
}
bool tprime(ll num)
{
    double y = sqrt(num);
    ll x = sqrt(num);
    return prime[x] && y == x;
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
ll cell(ull i, ull j)
{
    return (i - 1) * m + j;
}
ll custom_log(ll a, ll b)
{
    return log2(a) / log2(b);
}
vec primeFactors(int n)
{
    vec factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        factors.push_back(n);

    return factors;
}

int count2s(ll n)
{
    ll res = 0;
    ll c = 2;
    while (n > 1 && n % c == 0)
    {
        res++;
        n /= c;
    }
    return res;
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
ull fact(ull x)
{
    ull res = 1;
    while (x > 0)
        res *= x--;

    return res;
}
ll count_bin_ones(ll n)
{
    int c = 0;
    int i = 1;
    while (n)
    {
        if (n & 1)
            c++;
        n = n >> 1;
    }
    return c;
}
// mask & (1 << i)
//   int MAX = 1 << N;
int bitMaskFirst(string s)
{
    const int N = s.size();
    int MAX = 1 << N;
    for (int mask = 1; mask < MAX; mask++)
    {
        string subSq = "";
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
                subSq += s[i];
        }
    }
}
bool value(map<ll, ll> &mp)
{
    bool ex = false;

    for (auto [_, val] of mp)
        ex = ex || val;

    return ex;
}
ll num_len(ll n)
{
    ll res = 0;
    while (n)
    {
        if (n % 10)
            res++;
        n /= 10;
    }
    return res;
}
// data endcoding
// partial[n + 2]{};
// if (prefix[r1] - prefix[l1 - 1] > prefix[r2] - prefix[l2 - 1])
//     partial[l1]++, partial[r1 + 1]--;
// else if (prefix[r1] - prefix[l1 - 1] < prefix[r2] - prefix[l2 - 1])
//     partial[l2]++, partial[r2 + 1]--;

// for (int i = 1; i < n + 2; i++)
//     partial[i] += partial[i - 1];

ull acc(vec &nums)
{
    ull sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    return sum;
}

ull sigma(ull x)
{
    return x * (x + 1) / 2;
}
ull sigmaSquared(ull x)
{
    return (((x * ((x + 1))) * (((x * 2) + 1)))) / 6;
}
ull acc(vec &nums)
{
    ull sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
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
ull mod(ull equ)
{
    return equ % MOD;
}
// valid sub arrays
//  while (r < n)
//     {
//         while (l < n && nums[r] < i)
//         {
//             l++;
//             i--;
//         }
//         res += r - l + 1;
//         r++;
//         i++;
//     }