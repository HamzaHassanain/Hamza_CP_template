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
bool global_use_test_case = false;
#define use_double(num)        \
    cout << setprecision(num); \
    cout << fixed;
#define use_clock global_use_clock = true;
#define use_test_case global_use_test_case = true;
#define space << " " <<
#define spaceEnd << " "

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
ull MOD = 1e9 + 7;

#define sz(cont) size(cont)
#define of :
#define end "\n"
#define null nullptr
#define NO return void(cout << "NO" << end)
#define YES return void(cout << "YES" << end)
#define no return void(cout << "No" << end)
#define yes return void(cout << "Yes" << end)
#define all(vec) vec.begin(), vec.end()
#define allrev(vec) vec.rbegin(), vec.rend()
#define forn(i, n) for (ll i = 0; i < n; ++i)
#define for1n(i, n) for (ll i = 1; i <= n; ++i)
#define forr(i, n) for (ll i = n - 1; i >= 0; --i)
#define negMod(n, m) (n % m + m) % m
bool by_len(string &a, string b)
{
    return a.size() < b.size();
}
template <typename T>
istream &operator>>(istream &in, vector<T> &into)
{
    for (ll i = 0; i < size(into); i++)
        in >> into[i];

    return in;
}
template <typename T, typename S>
istream &operator>>(istream &in, vector<pair<T, S>> &into)
{
    for (ll i = 0; i < size(into); i++)
        in >> into[i].first >> into[i].second;

    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &outto)
{
    for (ll i = 0; i < size(outto); i++)
        out << outto[i] << " ";
    out << end;
    return out;
}
template <typename T>
ostream &operator<<(ostream &out, deque<T> &outto)
{
    for (ll i = 0; i < size(outto); i++)
        out << outto[i] << " ";
    out << end;
    return out;
}
template <typename T, typename S>
ostream &operator<<(ostream &out, vector<pair<T, S>> &outto)
{
    for (ll i = 0; i < size(outto); i++)
        out << outto[i].first << " " << outto[i].second << end;
    return out;
}
template <typename T, typename S>
ostream &operator<<(ostream &out, pair<T, S> &outto)
{
    out << outto.first << ":" << outto.second << end;
    return out;
}
#define sep cout << "===================================" << endl;
#define rv(exp) return void(cout << exp << end)
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

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
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
void out()
{
}
template <typename First, typename... Strings>
void out(First arg, const Strings &...rest)
{
    std::cout << arg;
    out(rest...);
}

void test_case()
{
}
int main()
{

    use_test_case;
    auto t1 = high_resolution_clock::now();
    FastIO();
    ll tc = 1;
    if (global_use_test_case)
        cin >> tc;
    while (tc--)
        test_case();
    auto t2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    if (global_use_clock)
        cout << end << ms_double.count() << "milliseconds\n";
}