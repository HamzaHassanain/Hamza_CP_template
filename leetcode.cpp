#include <bits/stdc++.h>

using namespace std;
#define print(nums, n)                \
    for (long long i = 0; i < n; i++) \
        cout << nums[i] << " ";       \
    cout << endl;

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
    int minDistance(string word1, string word2)
    {
        const int n = word1.size();
        const int m = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for (int i = 0; i < m; i++)
            dp[i][n] = m - i;
        for (int i = 0; i < n; i++)
            dp[m][i] = n - i;
        dp[m][n] = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (word1[j] != word2[i])
                    dp[i][j] = min(min(dp[i][j + 1], dp[i + 1][j]), dp[i + 1][j + 1]) + 1;
                else
                    dp[i][j] = dp[i + 1][j + 1];
            }
        }

        return dp[0][0];
    }
};

int main()
{
    FastIO();
    string w1 = "";
    string w2 = "";
    cin >> w1 >> w2;
    Solution sol;
    cout << sol.minDistance(w1, w2) << endl;
    // priority_queue<int, vector<int>,
}