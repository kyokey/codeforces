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
#define   SZ(a)         ((int)((a).size()))
#define   ALL(x) 	x.begin(),x.end()
#define   mabs(a)     ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     1000061
#define  eps      1e-6
int mi1[MAXN];
int mi2[MAXN];
int N;
int a[MAXN];
int d1[MAXN];
int d2[MAXN];
int v[MAXN];
void do1()
{
    clr(v);v[0]=inf;int mp=0;
    rep(i,1,N+1)
    {
        int l=0,r=mp,ret=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[i]<v[mid]) ret=mid,l=mid+1;
            else r=mid-1;
        }
        ret++;v[ret]=min(a[i],v[ret]);
        mp=max(mp,ret);
        d1[i]=ret;
    }
}
void do2()
{
    v[0]=0;int mp=0;rep(i,1,N+1) v[i]=inf;
    rep(i,1,N+1)
    {
        int l=0,r=mp,ret=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(a[i]>v[mid]) ret=mid,l=mid+1;
            else r=mid-1;
        }
        ret++;v[ret]=min(a[i],v[ret]);
        mp=max(mp,ret);
        d2[i]=ret;
    }
}
int main()
{
    scanf("%d",&N);
    REP(i,N) scanf("%d",a+i);
    REP(i,N) mi1[a[i]]=i+1;
    REP(i,N) scanf("%d",a+i);
    REP(i,N) mi2[a[i]]=i+1;
    REP(i,N) a[mi1[i+1]]=mi2[i+1];
 //   rep(i,1,N+1) printf("%d ",a[i]);printf("\n");
    do1();
    reverse(a+1,a+N+1);
    do2();
    reverse(d2+1,d2+N+1);
    int ret=0;
 //   rep(i,1,N+1) printf("%d ",d1[i]);printf("\n");
 //   rep(i,1,N+1) printf("%d ",d2[i]);printf("\n");
    rep(i,1,N+1) ret=max(ret,d1[i]+d2[i]-1);
    printf("%d\n",ret);
    return 0;
}

