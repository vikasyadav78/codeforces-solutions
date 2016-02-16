#include<iostream>
#include<stack>
#include<vector>
#include<cstdio>
using namespace std;
#define MAX 1000
bool visited[MAX];
vector<int> G[MAX];

pair<int , int> DFS(int a)
{
    stack<int> S;
    S.push(a);
    visited[a] = true;
    int max_height = 0 , ans_vertex = 0;
    bool flag;
    int x;
    while(!S.empty())
    {
        x = S.top();
        flag = false;
        for(int i = 0 ; i < G[x].size() ; i++)
        {
            if(!visited[x])
            {
                flag = true;
                S.push(G[x][i]);
                visited[G[x][i]];
                break;
            }
        }
        if(S.size() > max_height)
        {
            max_height = S.size();
            ans_vertex = S.top();
        }
    }
    if(!flag)
        S.pop();
    return make_pair(ans_vertex,max_height);
}
