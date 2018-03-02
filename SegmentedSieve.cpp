#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(X,Y) X.push_back(Y)
vector<ll>pr;
bool ispr[50009],sispr[100009];
void siv()
{
    ll i,j;
    ispr[1]=1;
    for(i=4;i<=50000;i+=2)ispr[i]=1;
    pb(pr,2);
    for(i=3;i*i<=50000;i+=2)
    {
        if(ispr[i]==0)
        {
            pb(pr,i);
            for(j=i*i;j<=50000;j+=(2*i))ispr[j]=1;
        }
    }
    for(;i<=50000;i+=2)
        if(ispr[i]==0)pb(pr,i);
    //cout<<pr.size();
}

void solve(ll a,ll b,ll no)
{
    ll i=0,j,st,cnt=0;
    for(i=0;i<b-a+1;i++)sispr[i]=0;
    if(a<2)a=2;
    for(i=0;pr[i]*pr[i]<=b&&i<pr.size();i++)
    {
        st=pr[i]*(a/pr[i]);// finding starting point
        if(st<a)st+=pr[i];// st would be greater than or equal a and multiple of pr[i]
        if(st<(2*pr[i]))st=2*pr[i];
        for(j=st;j<=b;j+=(pr[i]))
            sispr[j-a]=1;

    }
    for(i=0;i<b-a+1;i++)if(sispr[i]==0)cnt++;
    printf("Case %lld: %lld\n",no,cnt);
}

int main()
{
    siv();

    ll t,i,a,b,no=0;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        solve(a,b,++no);
    }
    return 0;
}
