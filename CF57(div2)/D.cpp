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
#define  MAXN     100561
#define  eps      1e-6
typedef long long int64;
int64 dis[MAXN];
int N;
vector<pair<int,int> > E[MAXN];
void dfs(int u)
{
    REP(i,E[u].size())
    {
        int v=E[u][i].first,w=E[u][i].second;
        if(dis[v]==-1) dis[v]=dis[u]+w,dfs(v);
    }
}
int main()
{
    REP(i,MAXN) dis[i]=-1;
    scanf("%d",&N);
    int64 ret=0;
    REP(i,N-1)
    {
        int u,v,w;scanf("%d%d%d",&u,&v,&w);u--,v--;
        E[u].push_back(make_pair(v,w)),E[v].push_back(make_pair(u,w));
        ret+=2*w;
    }
    dis[0]=0;
    dfs(0);
    int64 mx=0;REP(i,N) mx=max(mx,dis[i]);
    ret-=mx;
    printf("%I64d\n",ret);
    return 0;
}
