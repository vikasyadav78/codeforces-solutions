#include <iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
bool cmp(const string& a , const string& b)
{
    return a + b < b + a;
}
int main()
{
    //cout << "Hello World!" << endl;
    ll n;
    cin >> n;
    //map<string , ll> str;
    vector<string> ans;
    while(n--)
    {
        string s;
        cin >> s;
        //str[s] = n;
        ans.push_back(s);
    }
    /*for(map<string , ll>::reverse_iterator i = str.rbegin() ; i != str.rend() ; i++)
        ans.push_back((i->first));*/
    sort(ans.begin() , ans.end() , cmp);
    //reverse(ans.begin() , ans.end());
    for(ll i = 0 ; i < ans.size() ; i++)
        cout << ans[i];
    return 0;
}
