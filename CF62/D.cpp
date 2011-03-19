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
#define  MAXN     61
#define  eps      1e-6
map<int,int> mii;
map<int,int> mvi;
int h,q;
char cs[MAXN];
int getv(int t)
{
    if(mii.count(t)) return mii[t];
    return 0;
}
int main()
{
    scanf("%d%d",&h,&q);
    REP(i,q)
    {
        scanf("%s",cs);
        if(cs[0]=='a')
        {
            int v,e;scanf("%d%d",&v,&e);
            for(int j=v;j>0;j>>=1) mii[j]+=e;
            mvi[v]+=e;
        }
        else
        {
            int pos=1;
            double p=1;
            double ret=0;
            int tv=0;
            REP(j,h+1)
            {
                int lv,rv;
                lv=rv=mvi[pos];
                lv+=getv(pos*2),rv+=getv(pos*2+1);
                if(tv>=lv&&tv>=rv)
                {
                    ret+=tv*p;
                    break;
                }
                if(j==h)
                {
                    ret+=max(lv,rv)*p;
                    break;
                }
                p*=0.5;
                if(lv>=rv)
                {
                    ret+=lv*p;
                    pos*=2;
                    tv=max(tv,rv);
                }
                else
                {
                    ret+=rv*p;
                    pos=pos*2+1;
                    tv=max(tv,lv);
                }
            }
            printf("%.9lf\n",ret);
        }
    }
    return 0;
}
