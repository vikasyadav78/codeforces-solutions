#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define MAX 100001
struct node {
    ll left;
    ll right;
    ll sum;
    ll best;
};
ll a[50009];
node tree[200009];

node makeNode(ll left , ll right , ll sum , ll best)
{
    node temp;
    temp.left = left;
    temp.right = right;
    temp.sum = sum;
    temp.best = best;
    return temp;
}
node combine(node L , node R)
{
    ll left = L.left;
    if(L.sum + R.left > left) left = L.sum + R.left;
    ll right = R.right;
    if(R.sum + L.right > right) right = R.sum + L.right;
    //ll sum = L.sum + R.sum;
    ll best = max(L.right + R.left , max(L.best , R.best));
    return makeNode(left , right , L.sum + R.sum , best);
}
node build(ll from , ll to , ll idx)
{
    if(from == to)
    {
        tree[idx] = makeNode(a[from] , a[from] , a[from] , a[from]);
        return tree[idx];
    }
    ll mid = (from + to)/2;
    node l = build(from , mid , 2*idx);
    node r = build(mid + 1 , to , 2*idx + 1);
    tree[idx] = combine(l , r);
    return tree[idx];
}
node query(ll index , ll from , ll to , ll a , ll b)
{
    if(from == a && to == b)
    {
        return tree[index];
    }
    ll mid = (from + to)/2;
    if(b <= mid)
        return query(2*index , from , mid , a , b);
    if(a > mid)
        return query(2*index+1 , mid + 1 , to , a , b);
    node l = query(index*2 , from , mid , a , mid);
    node r = query(index*2 + 1 , mid + 1 , to , mid + 1 , b);
    return combine(l , r);
}
void update(int from, int to, int index, int indexMod) {
    if (from == to && from == indexMod) {
        tree[index] = makeNode(a[from], a[from], a[from], a[from]);
        return;
    }
    int mid = (from+to)/2;
    if (indexMod <= mid) {
        update(from, mid, (index<<1), indexMod);
    } else {
        update(mid+1, to, (index<<1)+1, indexMod);
    }
    tree[index] = combine(tree[index<<1],tree[(index<<1)+1]);
}
ll n;
int main()
{
    scanf("%lld", &n);
    for(ll i = 1 ; i <= n ; i++)
        scanf("%lld",&a[i]);
    build(1 , n , 1);
    ll t , L , R , type;
    scanf("%lld",&t);
    for(ll i = 0 ; i < t ; ++i)
    {
        scanf("%lld %lld %lld",&type , &L , &R);
        if(type == 0)
        {
            a[L] = R;
            update(1 , n , 1 , L);
        }
        else
            printf("%lld\n" , query(1 , 1 , n , L , R).best);
    }
    return 0;
}
