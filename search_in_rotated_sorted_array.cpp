

coding ninjas search in rotated sorted array

#include <bits/stdc++.h>

    int
    binarysearch(vector<int> &arr, int s, int e, int key)
{
    int start = s;
    int end = e;
    // if start  and end have so much value that the mid become outside the range of int then
    int mid = start + (end - start) / 2;
    // is videola last 10 min me h iska logic
    // int mid=start+(end-start)/2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
            // go to left part
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int findpivot(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = start + (end - start) / 2;

    while (start < end)
    { // start <= end likhte h to code bhut time lgata h run hone me

        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
            ;
        }
        mid = start + (end - start) / 2;
    }
    return start; // dry run me pta chala start or rnd ek hi jagah to lopp exit karke start pivot ko point krta h
    // yha return end bhi kr sakta h
}
int findPosition(vector<int> &arr, int n, int k)
{
    int pivot = findpivot(arr, n);
    if (k >= arr[pivot] && k <= arr[n - 1])
    {
        return binarysearch(arr, pivot, n - 1, k);
    }
    else
    {
        return binarysearch(arr, 0, pivot - 1, k);
    }
}
