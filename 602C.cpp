/***** peace23...PES college of engineering, mandya.........princy.krishnakeshav@gmail.com..... *****/
#include <iostream>
#include <queue>
using namespace std;
#define ll long long
int main()
{
    //cout << "Hello World!" << endl;
    // 0 -> train 1-> Bus
    ll n , m;
    cin >> n  >> m;
    ll a[n+1][n+1];
    for(ll i = 1 ; i <= n ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            a[i][j] = 1;
        }
    }
    ll x , y;
    for(ll i = 0 ; i < m ; i++)
    {
        cin >> x >> y;
        a[x][y] = 0;
        a[y][x] = 0;
    }
    ll distance[n+1];
    bool visited[n+1];
    for(ll i = 1 ; i <= n ; i++)
    {
        visited[i] = false;
        distance[i] = 0;
    }
    queue<ll> q;
    ll source = 1;
    q.push(source);
    //ll source = 1;
    visited[source] = true;
    while(!q.empty()){
        source = q.front();
        for(ll i = 1 ; i <= n ; i++)
        {
            if(a[source][i])
            {
                if(!visited[i])
                {
                    distance[i] = 1 + distance[source];
                    q.push(i);
                    visited[i] = true;
                }

            }
        }
        q.pop();
    }
    ll ans = distance[n];
    for(ll i = 1 ; i <= n ; i++)
    {
        visited[i] = false;
        distance[i] = 0;
    }
    //q.clear();
    source = 1;
    q.push(source);
    visited[source] = true;
    while(!q.empty())
    {
        source = q.front();
        for(ll i = 1 ; i <= n ; i++)
        {
            if(!a[source][i])
            {
                if(!visited[i])
                {
                    distance[i] = 1 + distance[source];
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        q.pop();
    }
    //cout << ans << " " << distance[n] << " ";
    if(ans == 0 ||  distance[n] == 0)
    {
        cout << "-1";
        return 0;
    }
    ans = max(ans , distance[n]);
    cout << ans;
    return 0;
}
