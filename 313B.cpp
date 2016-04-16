#include<iostream>
#include<string>
#include<vector>

using namespace std;

#define ll long long

int main()
{
    ll m , L , R;
    string s;
    cin >> s;
    cin >> m;
    vector<ll> dp(s.length());

    for(ll i = 1 ; i < s.length() ; i++)
    {
        if(s[i] == s[i-1])
            dp[i] = dp[i - 1] + 1;
        else
            dp[i] = dp[i - 1];

    }
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> L >> R;
        L-- , R--;
        cout << dp[R] - (dp[L]) << endl;
    }
    /*for(ll i = 0 ; i < s.length() ; i++)
        cout << dp[i] << " ";*/
    return 0;
}
