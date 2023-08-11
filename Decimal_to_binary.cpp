#include <iostream>
#include <math.h>
using namespace std;
int d2b(int n)
{
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 2;
        ans = digit * pow(10, i) + ans;
        i++;
        n = n / 2;
    }
    return ans;
}

int b2d(int n)
{
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;
        ans = digit * pow(2, i) + ans;
        i++;
        n = n / 10;
    }
    return ans;
}
int main()
{
    cout << "enter the number" << endl;
    int n;
    cin >> n;
    cout << d2b(n);

    // int n;
    // cin >> n;
    // cout << b2d(n);

    return 0;
}