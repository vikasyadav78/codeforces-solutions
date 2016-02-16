#include <iostream>
using namespace std;
#define ll long long
int main()
{
    //cout << "Hello World!" << endl;
    string t;
    ll min;
    cin >> t;
    cin >> min;
    ll hours = (t[0] - '0') * 10 + (t[1] - '0');
    ll minutes = (t[3] - '0') * 10 + (t[4] - '0');
    ll addHours = (min / 60);
    ll addMin = min % 60;

    hours += addHours;
    hours = hours % 24;
    minutes += addMin;
    if(minutes >= 60)
    {
        hours += 1;
        minutes = minutes % 60;
    }
    hours = hours % 24;
    if(hours < 10)
        cout << "0" << hours;
    else
        cout << hours;
    cout << ":";
    if(minutes < 10)
        cout << "0" << minutes;
    else
        cout << minutes;


    return 0;
}
