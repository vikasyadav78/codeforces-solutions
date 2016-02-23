#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n , k1 , k2 , x , y , steps = 0;
    deque<int> p1 , p2;
    cin >> n;
    cin >> k1;
    for(int i = 0 ; i < k1 ; i++)
    {
        cin >> x;
        p1.push_back(x);
    }
    cin >> k2;
    for(int i = 0 ; i < k2 ; i++)
    {
        cin >> x;
        p2.push_back(x);
    }
    while(!p1.empty() && !p2.empty())
    {
        x = p1.front();
        p1.pop_front();
        y = p2.front();
        p2.pop_front();
        if(x > y)
        {
            p1.push_back(y);
            p1.push_back(x);
            k1++;k2--;
            //p2.pop();
        }
        else if(x < y)
        {
            p2.push_back(x);
            p2.push_back(y);
            k1--;k2++;
            //p1.pop();
        }
        /*else
        {
            cout << "-1";
            return 0;
        }*/
       steps++;
       //if(p1.empty()){cout << steps << " " << 2;break;}
       //if(p2.empty()){cout << steps << " " << 1;break;}
       if(steps == 1050000){cout << -1;return 0;}
    }
    cout << steps << " ";
    if(p1.empty())cout << 2 << " ";
    if(p2.empty())cout << 1 << " ";

    return 0;
}
