#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll addMod(ll a, ll b, ll m)
{
    if (a + b < 0)
        return (a - m) + b;
    else if (a + b >= m)
        return a + b - m;
    else
        return a + b;
}
ll multiplyMod(ll a, ll b, ll m)
{
    if (b == 0 || a <=(9223372036854775807) / b)
        return (a * b) % m;
    ll result = 0;
    if (a > b) swap(a,b);
    while (a > 0)
    {
        if ((a & 1) != 0)
        {
            result = addMod(result, b, m);
        }
        a >>= 1;
        b -= m - b;
        if (b < 0)
            b += m;
    }
    return result;
}
ll bigMod(ll b,ll p,ll m)
{
    ll x=1,y=b%m;
    while(p>0)
    {
        if(p%2==1)
        {
            x=multiplyMod(x,y,m);
        }
        y=multiplyMod(y,y,m);
        p=p/2LL;
    }
    return x;
}
