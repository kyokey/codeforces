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
#define   ALL(x)        x.begin(),x.end()
#define   mabs(a)     ((a)>0?(a):(-(a)))
#define   inf         1000000001
#define  MAXN     10061
#define  eps      1e-6
int N;double k;
double a[MAXN];
bool isok(double mid)
{
        double nd=0;
        REP(i,N)
        {
            if(a[i]>=mid) nd+=(a[i]-mid)*k;
            else   nd-=(mid-a[i]);
        }
        return nd>=0;
}
int main()
{
    scanf("%d%lf",&N,&k);k=(100-k)/100;
    REP(i,N) scanf("%lf",a+i);
    double l=0,r=10000;
    sort(a,a+N);reverse(a,a+N);
    REP(step,100)
    {
        double mid=(l+r)/2;
        if(isok(mid)) l=mid;
        else r=mid;
    }
    printf("%.9lf\n",l);
    return 0;
}
