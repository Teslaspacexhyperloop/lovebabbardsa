#include <iostream>
using namespace std;
void reverse(int *arr, int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        swap(arr[i++], arr[j--]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return;
}

int linearsearch(int *arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i + 1;
        }
    }
}
int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    cout << linearsearch(arr, 5, 3);

    return 0;
}