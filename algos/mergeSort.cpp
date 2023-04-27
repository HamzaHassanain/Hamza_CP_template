#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll run_merge(vector<int> &arr, vector<int> &temp, int l, int mid, int r)
{
    ll cur_crossing = 0;

    int i, j, k;
    i = l;
    j = mid;
    k = l;

    while (i <= (mid - 1) && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            cur_crossing += (mid - i);
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return cur_crossing;
}
ll mergeSort(vector<int> &nums, vector<int> &temp, int l, int r)
{
    ll cur_crossing = 0;
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;
    cur_crossing = mergeSort(nums, temp, l, mid);
    cur_crossing += mergeSort(nums, temp, mid + 1, r);
    cur_crossing += run_merge(nums, temp, l, mid + 1, r);

    return cur_crossing;
}