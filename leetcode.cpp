#include <bits/stdc++.h>

using namespace std;

template <typename T>
istream &operator>>(istream &in, vector<T> &into)
{
    for (int i = 0; i < size(into); i++)
        in >> into[i];

    return in;
}
template <typename T>
ostream &operator<<(ostream &out, vector<T> &outto)
{
    for (int i = 0; i < size(outto); i++)
        out << outto[i] << " ";
    cout << endl;
    return out;
}
template <typename T, typename S>
ostream &operator<<(ostream &out, vector<pair<T, S>> &outto)
{
    for (int i = 0; i < size(outto); i++)
        out << outto[i].first << ":" << outto[i].second << endl;
    return out;
}
#define sep cout << "===================================" << endl;
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>

void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
#define maxHeap(type) priority_queue<type, vector<type>, less<type>>
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>

class Solution
{

public:
    string s, p;
    map<pair<int, int>, bool> memo;
    bool solve(int i, int j)
    {
        if (memo.find({i, j}) != memo.end())
            return memo[{i, j}];
        bool ans = 0;
        if (j == p.size())
            ans = i == s.size();

        else
        {

            bool firstMatch = i < s.size() && (s[i] == p[j] || p[j] == '.');
            if (j < p.size() - 1 && p[j + 1] == '*')
            {
                ans = solve(i, j + 2) || firstMatch && solve(i + 1, j);
            }
            else
                ans = firstMatch && solve(i + 1, j + 1);
        }

        return memo[{i, j}] = ans;
    }
    bool isMatch(string s, string p)
    {
        this->s = s;
        this->p = p;
        return solve(0, 0);
    }
};
int main()
{
    FastIO();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        /* code */
        string s1, s2;
        cin >> s1 >> s2;
        Solution sol;

        // cout << '.' + 0 << endl;
        cout << sol.isMatch(s1, s2) << endl;
        // priority_queue<int, vector<int>,
    }
}