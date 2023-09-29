#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

bool global_use_debug = false;
bool global_use_test_case = false;
#define use_double(num)        \
    cout << setprecision(num); \
    cout << fixed;
#define use_debug global_use_debug = true
#define use_test_case global_use_test_case = true
#define sp << " " <<
#define spe << " "

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vec;
typedef vector<pair<ll, ll>> vecp;
typedef vector<vector<ll>> vecv;
typedef vector<string> vecstr;
typedef pair<ll, ll> pl;
ll OO = 1e9;
ll OOO = 1e18;
#define sz(cont) (ll) size(cont)
#define of :
#define endl "\n"
#define EPS 1e-9
#define NO return void(cout << "NO" << endl)
#define YES return void(cout << "YES" << endl)
#define no return void(cout << "no" << endl)
#define yes return void(cout << "yes" << endl)
#define No return void(cout << "No" << endl)
#define Yes return void(cout << "Yes" << endl)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define negMod(n, m) (n % m + m) % m
#define rv(exp) return void(cout << exp << endl)
#define str string
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>
#define debug if (global_use_debug)
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
        freopen("input.in", "r", stdin), freopen("output.out", "w", stdout);
    }
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

    ll tc = 1;
    pre_init();
    if (global_use_test_case)
        cin >> tc;

    for (int i = 1; i <= tc; i++)
        test_case(i);
}
