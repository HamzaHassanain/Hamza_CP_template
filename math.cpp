
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
