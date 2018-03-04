#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f(ll n)
{
    if(n%2)
        return ((n+1)/2)*n;
    return (n+1)*(n/2);
}
void solve()
{
    ll x,c=0,i,j,n;
    scanf("%lld",&n);
    for(i=2;i*i<=n;i++)
    {
        j=(n/i);
        c+=(f(j)-f(i-1));
        c+=(i*(j-i));
    }
    printf("%lld\n",c);
}


int main()
{
    ll t,no=0;
    scanf("%lld",&t);
    while(t--)
    {
        printf("Case %lld: ",++no);
        solve();
    }
    return 0;
}
