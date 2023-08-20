#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;
    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    int k = s;

    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }
    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    int i = 0;
    int j = 0;
    int mainindex = s;
    while (i < len1 && j < len2)
    {
        if (first[i] <= second[j])
        {
            arr[mainindex++] = first[i];
            i++;
        }
        else
        {
            arr[mainindex++] = second[j];
            j++;
        }
    }
    while (i < len1)
    {
        arr[mainindex++] = first[i++];
    }

    while (j < len2)
    {
        arr[mainindex++] = second[j++];
    }
}
void mergesort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = s + (e - s) / 2;
    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);
    merge(arr, s, e);
}
int main()
{

    int arr[6] = {9, 510, 56, 98, 78, 45};
    mergesort(arr, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}