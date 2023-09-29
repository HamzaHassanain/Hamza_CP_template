#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    fstream bans("output.brute.out", ios::in);
    fstream ans("output.out", ios::in);
    int tc;
    bans >> tc;
    int cnt = 0;
    for (int t = 0; t < tc; t++)
    {
        long long a;
        ans >> a;

        string s;
        bans >> s;
        long long _a, _b, _c;
        bans >> _a >> _b >> _c;
        bans >> s;
        long long b;
        bans >> b;

        if (a != b)
        {
            cnt++;
            cout << "\033[1;31mWrong Answer on test case " << t + 1 << "\033[0m" << endl;
            cout << "Input: " << _a << " " << _b << " " << _c << endl;
            cout << endl;
            cout << "BANS: " << b << " ANS: " << a << endl;
            cout << endl;
        }
    }
    if (!cnt)
    {
        cout << "\033[1;32mAccepted\033[0m" << endl;
    }
}