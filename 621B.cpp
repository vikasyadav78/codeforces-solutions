#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll add[2001] , sub[2001];
int main()
{
    //cout << "Hello World!" << endl;
    ll n;
    cin >> n;
    vector< pair< ll , ll> > a;
    ll x , y  , ans = 0;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> x >> y;
        ans+=add[x+y];
        ans+=sub[1000 + (x - y)];
        add[x+y]++;
        sub[1000 + (x - y)]++;
    }
    cout << ans << endl;
    return 0;
}
