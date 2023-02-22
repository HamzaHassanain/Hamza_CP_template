#include <bits/stdc++.h>

using namespace std;
#define print(nums, n)                      \
    for (long long i = 0; i < n; i++)       \
        cout << bitset<12>(nums[i]) << " "; \
    cout << endl;

void FastIO()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}
class Solution
{
public:
    int ors(vector<int> &m)
    {
        int cur = 0;
        for (int x : m)
            cur = cur | x;
        return cur;
    }
    bool makesquare(vector<int> &m)
    {
        int side = 0;
        for (int match : m)
            side += match;
        cout << side << endl;
        if (side % 4)
            return false;
        else
            side /= 4;
        cout << side << endl;
        int n = m.size();
        const int mx = 1 << n;
        vector<int> masks;
        for (int mask = 1; mask < mx; mask++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                if (mask & (1 << j))
                    sum += m[j];
            }
            if (sum == side)
            {
                // cout << sum << endl;
                masks.push_back(mask);
            }
        }
        if (ors(masks) != mx - 1)
            return false;
        for (int i = 0; i < masks.size(); i++)
        {
            int cur1 = masks[i];
            for (int j = 0; j < masks.size(); j++)
            {
                if (i == j)
                    continue;
                int cur2 = masks[j];
                if (!(cur2 & cur1))
                    for (int k = 0; k < masks.size(); k++)
                    {
                        if (i == k || j == k)
                            continue;
                        int cur3 = masks[k];
                        if (!(cur2 & cur3) && !(cur1 & cur3))
                            for (int l = 0; l < masks.size(); l++)
                            {
                                if (i == l || j == l || l == k)
                                    continue;
                                int cur4 = masks[l];
                                if (!(cur4 & cur3) && !(cur4 & cur2) || !(cur4 & cur1))
                                    return true;
                            }
                    }
            }
        }
        return false;
    }
};

int main()
{
    FastIO();
    vector<int> str = {10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Solution sol;
    cout << sol.makesquare(str) << endl;
    // priority_queue<int, vector<int>,
}