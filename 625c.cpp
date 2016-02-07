#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //cout << "Hello World!" << endl;
    ll n , k;
    cin >> n >> k;
    ll a[n][n];
    ll table[n*n];
    for(ll i = 0 ; i < n*n ; i++)
        table[i] = 0;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
            a[i][j] = -1;
    }
    ll num = n*n; //cout << num;
    ll count = 0;
    ll sum = 0;
    num = num - n + k; //cout << num;
    for(ll i = 0 ; i < n ; i++)
    {
        a[i][k-1] = num;
        table[num] = 1;
        ll x = num+1;
        for(ll j = k ; j < n ; j++)
        {
            a[i][j] = x;
            table[x] = 1;
            x++;
        }
        sum += (num);
        //cout << num << " ";
        num = num - n + k - 1;
    }
    num = 1;
    cout << sum << endl;
    for(ll i = 0 ; i < n ; i++)
    {
        for(ll j = 0 ; j  < n ; j++)
        {
            if(a[i][j] == -1)
            {
                a[i][j] = num;
                num++;
            }
            
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    for(ll i = 0 ; i  < n ; i++)
    {
        for(ll j = 0 ; j < n ; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}