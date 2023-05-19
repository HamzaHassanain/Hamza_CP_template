// عَافِرِ وَ بتاع //
#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

bool global_use_clock = false;
bool global_use_test_case = false;
bool global_use_debug = false;
#define use_double(num)        \
    cout << setprecision(num); \
    cout << fixed;
#define use_debug global_use_debug = true;
#define use_clock global_use_clock = true;
#define use_test_case global_use_test_case = true;
#define sp << " " <<
#define spe << " "

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
typedef deque<ll> deq;
typedef vector<ull> vecull;
typedef vector<pair<ll, ll>> vecp;
typedef vector<vector<ll>> vecv;
typedef vector<set<ll>> vecset;
typedef vector<string> vecstr;
typedef pair<ll, ll> pl;
typedef map<ll, ll> mpll;
#define vec(type) vector<type>
#define deq(type) deque<type>
ll OO = 1e9;
ll OOO = 1e18;
ull MOD = 1e9 + 7;
ull MOD2 = 998244353;
#define sz(cont) (ll) size(cont)
#define of :
#define endl "\n"
#define null nullptr
#define NO return void(cout << "NO" << endl)
#define YES return void(cout << "YES" << endl)
#define no return void(cout << "no" << endl)
#define yes return void(cout << "yes" << endl)
#define No return void(cout << "No" << endl)
#define Yes return void(cout << "Yes" << endl)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define forn(i, init, n) for (ll i = init; i < n; ++i)
#define forr(i, init, n) for (ll i = init; i > n; --i)
#define negMod(n, m) (n % m + m) % m
#define rv(exp) return void(cout << exp << endl)
#define str string
#define cnt_set_bits __builtin_popcount
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>
#define use_getline cin.ignore(std::numeric_limits<std::streamsize>::max(), "\n")
#define rt return
#define debug if (global_use_debug)
bool by_len(string &a, string b)
{
    return a.size() < b.size();
}
#define sep               \
    if (global_use_debug) \
        cout << "===================================" << endl;
template <typename T>
istream &operator>>(istream &in, vector<T> &into)
{
    for (ll i = 0; i < size(into); i++)
        in >> into[i];

    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &outto)
{
    for (ll i = 0; i < size(outto); i++)
        out << outto[i] << " ";
    return out;
}
void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
}
void using_local()
{
    ifstream myfile;
    myfile.open("hamza_local");
    if (myfile)
    {
        use_debug;
        freopen("input", "r", stdin), freopen("output", "w", stdout);
    }
}

// عَافِرِ وَ بتاع //
/*
    4

    1     2    3   4  5    6



*/

vec factors(ll n)
{
    vec res;
    for (ll x = 1; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            if (n / x != x)
                res.push_back(n / x);
            res.push_back(x);
        }
    }

    return res;
}
void test_case(int case_num)
{
}
void pre_init()
{
    FastIO();
    using_local();

    use_test_case;
    debug use_test_case;
}
int main()
{

    auto t1 = high_resolution_clock::now();
    ll tc = 1;
    pre_init();
    if (global_use_test_case)
        cin >> tc;
    for (int i = 1; i <= tc; i++)
        test_case(i);
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    if (global_use_clock && global_use_debug)
        cout << endl
             << ms_double.count() << "ms\n";
}
