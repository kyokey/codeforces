#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>
using namespace std;
#define   sqr(a)         ((a)*(a))
#define   rep(i,a,b)  for(int i=(a);i<(int)(b);i++)
#define   per(i,a,b)  for(int i=((a)-1);i>=(int)(b);i--)
#define   PER(i,n)     per(i,n,0)
#define   REP(i,n)     rep(i,0,n)
#define   FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define   clr(a)      memset((a),0,sizeof (a))
#define   mabs(a)     ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     1000003
#define  MAXV     10000010
#define  eps      1e-6
typedef long long int64;
int pre[MAXN];
int a[MAXN];
int v[MAXV];
int64 gcd(int64 a,int64 b)
{
    return b==0?a:gcd(b,a%b);
}
int ufind(int u)
{
    if(pre[u]==u) return u;
    return pre[u]=ufind(pre[u]);
}
void dounion(int u,int v)
{
    u=ufind(u),v=ufind(v);
    pre[u]=v;
}
int main()
{
    int N;scanf("%d",&N);
    REP(i,N) scanf("%d",a+i);
    REP(i,MAXV) v[i]=-1;
    REP(i,N) v[a[i]]=i;
    REP(i,N) pre[i]=i;
    for(int64 i=1;i*i<MAXV;i++) for(int64 j=i+1;max(j*j-i*i,2*j*i)<=MAXV;j+=2)
    {
        if(gcd(i,j)==1)
        {
            int64 a=2*i*j,b=j*j-i*i,c=i*i+j*j;
            if(a<MAXV&&b<MAXV&&v[a]!=-1&&v[b]!=-1) dounion(v[a],v[b]);
            if(a<MAXV&&c<MAXV&&v[a]!=-1&&v[c]!=-1) dounion(v[a],v[c]);
            if(b<MAXV&&c<MAXV&&v[b]!=-1&&v[c]!=-1) dounion(v[b],v[c]);
        }
    }
    int ret=0;REP(i,N) if(pre[i]==i) ret++;
    printf("%d\n",ret);
    return 0;
}
