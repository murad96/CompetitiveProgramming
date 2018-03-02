#include<bits/stdc++.h>
using namespace std;
using namespace std;
typedef long long ll;
ll bigmod(ll a,ll b,ll m)
{
    long long x=1,y=a;
    while(b>0)
    {
        if(b & 1)
            x=(x*y)%m;
        y=(y*y)%m;
        b>>=1;
    }
    return x;
}
ll gcd(ll a,ll b)
{
    ll rem=0;
    if(b==0)return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a/gcd(a,b))*b;
}
////========== End of Templates ==============////


int extends_euclid(int a,int b,int &x,int &y)
{
    int x1,y1,d;
    if(a==0)
    {
        x=0;
        y=1;
        return b;
    }
    d=extends_euclid(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}


int main()
{
    //For AX+BY=D ; D=GCD(A,B);
    int a,b,x,y;
    int d;
    while(scanf("%d %d",&a,&b)==2)
    {

        d=extends_euclid(a,b,x,y);

        if (a == b)
        {
            x = 0;
            y = 1;
        }
        printf("%d %d %d\n",x,y,d);

    }
    return 0;
}

