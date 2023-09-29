#include <bits/stdc++.h>

using namespace std;
long long get_rand(long long l, long long r)
{
    if (r < l)
        r = l;

    return l + (rand() % (r - l + 1));
}
void create_test_set(long long n)
{
    cout << get_rand(1, n) << " " << get_rand(1, n) << " " << get_rand(1, n) * get_rand(1, n) << endl;
    cout << get_rand(n, 2 * n) << " " << get_rand(1, n) << " " << get_rand(n, n) * get_rand(n, 2 * n) << endl;
    cout << get_rand(1, n) << " " << get_rand(n, 3 * n) << " " << get_rand(1, 10 * n) << endl;
    cout << get_rand(1, n) << " " << get_rand(1, n) << " " << get_rand(1, n / 2) << endl;
    cout << get_rand(1, n) << " " << get_rand(1, n / 2) << " " << get_rand(1, n / 2) << endl;
    cout << get_rand(1, n / 3) << " " << get_rand(n, 3 * n) << " " << get_rand(1, n) << endl;
    cout << get_rand(1, n / 4) << " " << get_rand(1, 3 * n) << " " << get_rand(1, 4 * n) << endl;

    cout << get_rand(1, n / 2) << " " << get_rand(1, n / 2) << " " << get_rand(1, n / 2) << endl;
    cout << get_rand(1, n / 3) << " " << get_rand(n, 3 * n) << " " << get_rand(1, n) << endl;
    cout << get_rand(1, n) << " " << get_rand(1, 3 * n) << " " << get_rand(2 * n, 4 * n) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("input.in", "w", stdout);
    // number of odd numbers between 1 and 101 = 50
    int tc = 100 * 10;
    cout << tc << endl;
    for (int i = 1; i <= 1000; i++)
        if (i % 2)
            create_test_set(i);
}