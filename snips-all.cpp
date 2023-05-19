#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

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

#define rt return
#define debug if (global_use_debug)
/// sieve //////////////////////////////////////
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

/// bs_sqrt //////////////////////////////////////
ll bs_sqrt(ll x)
{
    ll left = 0, right = 2000000123;
    while (right > left)
    {
        ll mid = (left + right) / 2;

        if (mid * mid > x)
            right = mid;
        else
            left = mid + 1;
    }
    return left - 1;
}
/// createPalindrome //////////////////////////////////////
int createPalindrome(int input, int b, bool isOdd)
{
    int n = input;
    int palin = input;

    if (isOdd)
        n /= b;

    while (n > 0)
    {
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
vec palands;
void generatePalindromes(int n)
{
    int number;

    for (int j = 0; j < 2; j++)
    {
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n)
        {
            palands.push_back(number);
            i++;
        }
    }
}
/// @brief ///////////////////////////////
ull fact(ull x)
{
    ull res = 1;
    while (x > 0)
        res *= x--;

    return res;
}
/// @brief ///////////////////////////////
ll custom_log(ll a, ll b)
{
    return log2(a) / log2(b);
}
ll fast_pow(ll a, ll b)
{
    a %= MOD;
    if (a == 0)
        return 0;
    ll product = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            product *= a;
            product %= MOD;
            --b;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return product;
}
/// nCr //////////////////////////////////
vec factorial(1e6);
ll modular_inverse(ll n)
{
    return fast_pow(n, MOD - 2);
}

ll nCr(ll n, ll k)
{

    if (n == k || !k)
        return 1;
    return (factorial[n] * modular_inverse(factorial[k] * factorial[n - k])) % MOD;
}
ll cur = 1;
for (ll i = 1; i < 1e6; i++)
{
    cur *= i;
    cur %= MOD;
    factorial[i] = cur;
}
/// primeFactors//////////////////////////////////
vec primeFactors(ll n)
{
    vec factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i * i <= n; i = i + 2)
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
/// extended_ecluid //////////////////////////////////
long long extended_ecluid(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = extended_ecluid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
/// mx_subseq_sum //////////////////////////////////
ll mx_subseq_sum(vec &nums)
{
    ll cur = 0;
    ll mx = -OOO;

    for (int i = 0; i < nums.size(); i++)
    {
        cur += nums[i];
        if (cur <= 0)
            cur = 0;
        mx = max(cur, mx);
    }

    rt mx;
}

/// snoob //////////////////////////////////
uint64_t snoob(uint64_t x)
{
    uint64_t smallest, ripple, ones;
    smallest = x & -x;
    ripple = x + smallest;
    ones = x ^ ripple;
    ones = (ones >> 2) / smallest;

    rt(ripple | ones);
}

/// Str_Sub_Digit_Res //////////////////////////////////
struct Str_Sub_Digit_Res
{
    int r;
    int b;
    Str_Sub_Digit_Res() {}
};
Str_Sub_Digit_Res subDigits(char c1, char c2, int b)
{
    Str_Sub_Digit_Res res;
    int d1 = c1 - '0';
    int d2 = c2 - '0';
    int n = d1 - d2 - b;
    if (n >= 0)
    {
        res.r = n;
        res.b = 0;
    }
    else
    {
        res.r = n + 10;
        res.b = 1;
    }
    return res;
}
string stripLeadingZero(string s)
{
    string new_s = s;
    int i = 0;
    while (i < s.size() && s[i] == '0')
        i++;
    if (i == s.size())
        return "0";
    return s.substr(i);
}
string str_sub(string a, string b)
{
    int borrow = 0;
    string res;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        Str_Sub_Digit_Res t = subDigits(a[i], b[i], borrow);
        borrow = t.b;
        res = char('0' + t.r) + res;
    }

    return stripLeadingZero(res);
}

/// TO BASE K /////////////////////////
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char *fromDeci(char res[100], ll base, ll inputNum)
{
    int index = 0;

    while (inputNum > 0)
    {
        res[index++] = reVal(inputNum % base);
        inputNum /= base;
    }
    res[index] = '\0';

    strev(res);

    return res;
}
ull sigmaSquared(ull x)
{
    return (((x * ((x + 1))) * (((x * 2) + 1)))) / 6;
}

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