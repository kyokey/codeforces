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
#define  MAXN     1011
#define  SZ(a)    ((int)((a).size()))
#define  eps      1e-6
int N;
vector<int> val[MAXN];
vector<int> pre[MAXN];
int a[MAXN];
int getv(int v,int j,int k)
{
    int top=0;
    while(v>0) a[top++]=v%10,v/=10;
    reverse(a,a+top);
    a[j]=k;
    int ret=0;
    REP(i,top) ret=ret*10+a[i];
    return ret;
}
int main()
{
    scanf("%d",&N);
    REP(i,N)
    {
        int v;scanf("%d",&v);
        REP(j,4) REP(k,10)
        {
            int nv=getv(v,j,k);
            if(nv<1000||nv>2011) continue;
            val[i].push_back(nv);
            if(i==0)pre[i].push_back(-1);
            else
            {
                bool f=false;
                REP(p,SZ(val[i-1])) if(val[i-1][p]<=nv)
                {
                    if(i-1==0||i>1&&pre[i-1][p]!=-1)
                    {
                        f=true;pre[i].push_back(p);break;
                    }
                }
                if(!f) pre[i].push_back(-1);
            }
        }
    }
    if(N==1)
    {
        if(val[0].size()>0) printf("%d\n",val[0][0]);
        else printf("No solution\n");
        return 0;
    }
    int mini=-1;
    REP(i,SZ(pre[N-1])) if(pre[N-1][i]!=-1) mini=i;
    if(mini==-1)
    {
        printf("No solution\n");
        return 0;
    }
    vector<int> res;
    for(int i=N-1;i>=0;i--)
    {
        res.push_back(val[i][mini]);
        mini=pre[i][mini];
    }
    reverse(res.begin(),res.end());
    REP(i,SZ(res)) printf("%d\n",res[i]);
    return 0;
}
