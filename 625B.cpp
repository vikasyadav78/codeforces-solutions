#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    //cout << "Hello World!" << endl;
    string a , b;
    cin >> a >> b;
    ll len1 = a.length();
    ll len2 = b.length();
    ll count , ans = 0;
    for(ll i = 0 ;  i < len1 - len2 + 1  ;)
    {
        count = 0;
        for(ll j = 0 ; j < len2 ; j++)
        {
            if(b[j] == a[i+j])
                count++;
        }
        if(count == len2)
        {
            ans++;
            i+=count;
        }
        else
            i++;
    }
    cout << ans;
    return 0;
