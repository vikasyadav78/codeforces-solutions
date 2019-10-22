#include <iostream>
using namespace std;

int main()
{
    //cout << "Hello World!" << endl;
    int n , ans = 0 , count = 0;
    cin >> n;
    int a[n+9];  //Creating an array of size a
    for(int i = 1 ; i <= n ;i++)
        cin >> a[i];
    for(int i = 1 ; i <= n ;i++)
    {
        count = 0;
        int x = a[i];
        while(x != -1)
        {
            x = a[x];      
            count++;
        }
        ans = max(ans , count);    //Finding maximum between ans and count
    }
    cout << ans+1;  // Incrementing ans by 1
    return 0;
}

