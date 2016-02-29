#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n , k;
    cin >> n >> k;
    ll a[n];
    for(ll i = 0 ; i < n ; i++)
        cin >> a[i];
    ll _max = a[n-1];
    for(ll i = 0  ; i < n - k ; i++)
        _max = max(_max , a[i] + a[2 * (n-k) - i - 1]);
    cout << _max;
    return 0;
}
