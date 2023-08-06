#include <iostream>
using namespace std;
int main()
{
    // int a, b;
    // // how to read space tab and enter using cin
    // a = cin.get();
    // cout << "the value of a is" << a << endl;
    // // it gives ascii value
    // // tab=9
    // // space=32
    // // enter=10
    // // a man has 70 rupee write a loop each kela cost 10

    // // int paisa=70;
    // // while(paisa>0){
    // //         paisa=paisa-10;
    // //     cout<<"kha lo kela"<<endl;
    // // }
    // // print 1 to n using while loop
    // // int n;
    // // cin>>n;
    // // int i=1;
    // // while(i<=n){
    // //     cout<<i<<endl;
    // //     i++;
    // // }
    // // find sum till 1 to n using while loop
    // // int n;
    // // cin>>n;
    // // int i=1;
    // // int sum=0;// isi sum ko agarandar declare karta to access nhi kr pata sum ko result me bahar
    // // while(i<=n){
    // //     sum=sum+i;
    // //     i++;
    // // }
    // // cout<<"the value of sum is"<<sum<<endl;
    // // find sum of all even no till n
    // /*
    // int n;
    // cin>>n;
    // int i=2;
    // int sum=0;
    // while(i<=n){
    //     sum=sum+i;
    //     i=i+2;
    // }
    // cout<<"the value of sum is"<<sum<<endl;
    // */

    // // make a table which convert farhenheit to celsius

    // // check prime no
    // int n;
    // cin >> n;
    // int i = 2;
    // while (i < n)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << "non prime" << i << endl;
    //     }
    //     else
    //     {
    //         cout << "prime" << i << endl;
    //     }
    // }
    // printing fibonacci sequence
    int a = 0;
    int b = 1;
    int sum;
    for (int i = 0; i < 10; i++)
    {
        sum = a + b;
        cout << sum << " ";
        a = b;
        b = sum;
    }

    return 0;
}
