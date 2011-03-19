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
#define  MAXN     10011
#define  SZ(a)    ((int)((a).size()))
#define  eps      1e-6
int N;
typedef struct PT
{
    double x,y,z;
}PT;
PT a[MAXN];
double vp,vx;
double px,py,pz;
double getdis(double x,double y,double z,double a,double b,double c)
{
   double ret=sqr(x-a)+sqr(y-b)+sqr(z-c);
   return max(.0,sqrt(ret));
}
double doit(int i,double tm,double &rx,double &ry,double &rz)
{
    double ax=a[i].x,ay=a[i].y,az=a[i].z;
    double bx=a[i+1].x,by=a[i+1].y,bz=a[i+1].z;
    double x=ax,y=ay,z=az;
    double ret=1e99;
    double tt=getdis(bx,by,bz,ax,ay,az)/vx;
    double dis=getdis(bx,by,bz,ax,ay,az);
    double l=0,r=tt;
    REP(j,100)
    {
        double mid=(l+r)/2;
        rx=ax+mid/tt*(bx-ax),ry=ay+mid/tt*(by-ay),rz=az+mid/tt*(bz-az);
        double ps=getdis(px,py,pz,rx,ry,rz)/vp;
        if(mid+tm+1e-11<ps) l=mid;
        else r=mid,ret=mid+tm;
    }
    return ret;
}
int main()
{
    scanf("%d",&N);N++;
    REP(i,N) scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
    scanf("%lf%lf",&vp,&vx);
    scanf("%lf%lf%lf",&px,&py,&pz);
    double rx,ry,rz;
    double ret=1e90;
    double tm=0;
    REP(i,N-1)
    {
        double tx,ty,tz;
        double tmp=doit(i,tm,tx,ty,tz);
        tm+=getdis(a[i].x,a[i].y,a[i].z,a[i+1].x,a[i+1].y,a[i+1].z)/vx;
        if(tmp<ret) ret=tmp,rx=tx,ry=ty,rz=tz;
    }
    if(ret>1e80)
    {
        printf("NO\n");return 0;
    }
    printf("YES\n");
    printf("%.10lf\n",ret);
    printf("%.10lf %.10lf %.10lf\n",rx,ry,rz);
    return 0;
}
