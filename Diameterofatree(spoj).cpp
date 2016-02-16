#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;
#define MAX 10000
char matrix[MAX][MAX];
bool visited[MAX][MAX];
bool finalVisited[MAX][MAX];
//vector<pair<int , int>>graph[MAX];
int c , r;
pair <int, pair <int , int > > DFS(int x , int y)
{
    int max_height = 0;
    pair<int , int> ans;
    stack <pair <int , int> >S;
    visited[x][y] = true;
    S.push(make_pair(x , y));
    bool flag = false;
    while(!S.empty())
    {
        x = S.top().first;
        y = S.top().second;
        flag = false;
        if((y+1) < c && !visited[x][y+1] && matrix[x][y+1] == '.')
        {
            S.push(make_pair(x , y+1));
            visited[x][y+1] = true;
            flag = true;
        }
        else if((x + 1) < r && !visited[x+1][y] && matrix[x+1][y] == '.')
        {
            S.push(make_pair(x+1 , y));
            visited[x+1][y] = true;
            flag = true;
        }
        else if(y > 0 && !visited[x][y-1] && matrix[x][y-1] && matrix[x][y-1] == '.')
        {
            S.push(make_pair(x , y - 1));
            visited[x][y-1] = true;
            flag = true;
        }
        else if(x > 0 && !visited[x-1][y] && matrix[x-1][y] && matrix[x-1][y] == '.')
        {
            S.push(make_pair(x - 1 , y));
            visited[x-1][y] = true;
            flag = true;
        }
        if(S.size() > max_height)
        {
            max_height = S.size();
            ans  = S.top();
        }
        if(!flag)
            S.pop();
    }
    return make_pair(max_height , ans);
}
int findDiameter(int x , int y)
{
    pair<int , pair<int , int> > leaf = DFS(x,y);
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            if(visited[i][j])
            {
                finalVisited[i][j] = true;
                visited[i][j] = false;
            }
        }
    }
    return DFS(leaf.second.first , leaf.second.second).first;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> c >> r;
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                visited[i][j] = false;
                finalVisited[i][j] = false;
            }
        }
        for(int i = 0 ; i < r ; i++)
                cin >> matrix[i];
        int diameter = 0;
        for(int i = 0 ; i < r ; i++)
        {
            for(int j = 0 ; j < c ; j++)
            {
                if(!finalVisited[i][j] && matrix[i][j] == '.')
                {
                    //finalVisited[i][j] = true;
                    diameter = max(diameter , findDiameter(i , j) - 1);
                }
            }
        }
        cout << "Maximum rope length is " << diameter << "." << endl;
    }
    return 0;
}
