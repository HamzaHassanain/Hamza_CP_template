#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    freopen("input.in", "r", stdin), freopen("output.brute.out", "w", stdout);

    int tc;
    cin >> tc;
    cout << tc << endl;
    for (int t = 1; t <= tc; t++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Input: ";
        cout << a << " " << b << " " << c << endl;
        cout << "Expected: ";

        long long k = 0;
        for (long long i = 0; i <= c / a + 10; i++)
        {
            for (long long j = 0; j <= c / b + 10; j++)
            {
                if (i * a + j * b <= c)
                {
                    long long curChees = i + 2 * j;
                    long long curBurg = i + j * 2;
                    long long curBread = i * 2 + j * 2 - 1;
                    k = max(k, min(curChees, min(curBurg, curBread)));
                }
            }
        }
        cout << k << endl;
    }
}