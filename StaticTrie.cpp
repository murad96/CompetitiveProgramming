/* In the name of Allah
   The most beneficent,
   The most merciful
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dbl double
#define vl vector<ll>
#define sf(zz) scanf("%I64d",&zz)
#define sf2(zz,zzz) scanf("%I64d %I64d",&zz,&zzz)
#define sf3(zz,zzz,zzzz) scanf("%I64d %I64d %I64d",&zz,&zzz,&zzzz)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define reset(a,d) memset(a,d,sizeof(a))
#define pb(a,b) a.push_back(b)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define ALL(x) (x).begin(),(x).end()
#define LLA(x) x.rbegin(), x.rend()
#define SORT(v) sort(ALL(v))
#define inf   1e15
#define mod   1000000007
#define PI acos(-1.0)
string sss="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//-----------------------------------------------------------//
struct node
{
    int next[28];
    bool endmark;
}Trie[100009];
int cur,last;
void Reset(int koto)
{
    for(int i=0;i<27;i++)Trie[koto].next[i]=-1;
    Trie[koto].endmark = 0;
}
void Insert(string s)
{
        ll i,j,l=s.size();
        for(i=0;i<l;i++)
        {
            int now = s[i] - 'a';
            if(Trie[cur].next[now] == -1)
            {
                Trie[cur].next[now]=last;
                Reset(last++);
                cur = last - 1;
            }
            else
            {
                cur = Trie[cur].next[now];
            }
        }
        Trie[cur].endmark = 1;
}
bool Check(string s)
{
        ll i,j,l=s.size();
        for(i=0;i<l;i++)
        {
            int now = s[i] - 'a';
            if(Trie[cur].next[now] == -1)
            {
                return 0;
            }
            else
            {
                cur = Trie[cur].next[now];
            }
        }
        return Trie[cur].endmark;
}
void solve(ll CS)
{
    int q,type,i,j;
    cin>>q;
    string s;
    last = 1;
    Reset(0);
    while(q--)
    {
        s.clear();
        cur=0;
        cin>>type>>s;
        if(type==1)
            Insert(s);
        else cout<<Check(s)<<endl;
    }
}

int main()
{
    ll t,no=0;
    t=1;
    //sf(t);
    while(t--)solve(++no);
}
