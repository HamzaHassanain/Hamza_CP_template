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