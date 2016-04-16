#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //cout << "Hello World!" << endl;
    ll t;
    cin >> t;
    ll test = t;
    while(t--)
    {
        ll n , ans = 0;
        
        cin >> n;
        
        vector<ll>V1(n) , V2(n);
        
        for(ll i = 0 ; i < n ; i++)
            cin >> V1[i];
        
        for(ll i = 0 ; i < n ;i++)
            cin >> V2[i];
        
        sort(V1.begin() , V1.end());
        
        sort(V2.begin() , V2.end());
        
        for(ll i = 0 ; i < n ; i++)
            ans += (V1[i] * V2[n - i - 1]);
        
        cout << "Case #" << test - t << ": " << ans << endl; 
    }
    return 0;
}
