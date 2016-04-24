#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<sstream>
using namespace std;

int main()
{
    int t , n , m;;
    cin >> t;
    int test = t;
    while(t--)
    {
       set<string> set1 , set2;
       cin >> n >> m;
       for(int i =0 ; i < n ; i++)
       {
           string s;
           cin >> s;
           set1.insert(s);
       }
       for(int i = 0 ; i < m ; i++)
       {
           string s;
           cin >> s;
           set2.insert(s);
           //string ss = "/";
           for(int j = 1 ; j < s.length() ; ++j)
           {
               if(s[j] == '/')
               {
                   set2.insert(s.substr(0 , j));
               }
           }
       }
       int ans = 0;
       for(set<string>::iterator i = set2.begin() ; i != set2.end() ; i++)
       {
           if(!set1.count(*i))
                ans++;
       }
       cout << "Case #" << test - t << ": " << ans << endl;
    }
    return 0;
}
