#include <bits/stdc++.h>
int mergeArray(long long *arr, int l, int mid, int r)
{
    int left = l, right = mid + 1, count = 0;
    vector<int> temp;
    while (left <= mid && right <= r)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            count += (mid - left + 1);
            // cout << "Pair " << arr[l] << "," << arr[r] << "count " << count << "\n";
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= r)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];
    return count;
}
void mergeSort(long long *arr, int l, int r, long long &ans)
{
    if (l == r)
        return;

    int mid = (l + r) / 2;

    mergeSort(arr, l, mid, ans);
    mergeSort(arr, mid + 1, r, ans);
    ans += mergeArray(arr, l, mid, r);
}
long long getInversions(long long *arr, int n)
{
    // Write your code here.
    long long ans = 0;
    mergeSort(arr, 0, n - 1, ans);
    return ans;
}