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
    int pivot = 0;
    int compress(vector<char> &chars)
    {
        int n = chars.size();
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && chars[i] == chars[j])
                j++;
            int len = j - i;
            chars[pivot++] = chars[i];
            if (len > 1)
                chars[pivot++] = len + '0';
            // cout << pivot << endl;
            i = j - 1;
        }
        print(chars, n);

        return pivot;
    }
};
int main()
{
    FastIO();
    vector<char> chars = {'a', 'a', 'c', 'c', 'c', 'c', 'c'};
    // vector<char> chars = {'a'};
    Solution sol;
    cout << sol.compress(chars) << endl;
    // priority_queue<int, vector<int>,
}