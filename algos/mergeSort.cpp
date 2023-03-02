#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, size(nums) - 1);

        return nums;
    }
    void mergeSort(vector<int> &nums, int l, int r)
    {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }
    void merge(vector<int> &arr, int l, int mid, int r)
    {

        int n1 = mid - l + 1;
        int n2 = r - mid;

        int L[n1], M[n2];

        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            M[j] = arr[mid + 1 + j];

        int i, j, k;
        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= M[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = M[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = M[j];
            j++;
            k++;
        }
    }
};