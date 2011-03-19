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
#define  MAXN     1061
#define  eps      1e-6
char cs[MAXN];
int a[MAXN];
bool visited[MAXN];
bool G[MAXN][MAXN];
int indegree[MAXN];
int pre[MAXN];
int N;
int ufind(int x)
{
    return x==pre[x]?x:(pre[x]=ufind(pre[x]));
}
void dounion(int u,int v)
{
    u=ufind(u),v=ufind(v);
    pre[u]=v;
}
int main()
{
    scanf("%d%s",&N,cs);
    REP(i,N)pre[i]=i;
    int n=strlen(cs);
    REP(i,n) if(cs[i]=='=') dounion(i,i+1);
    REP(i,N) ufind(i);
    clr(G);
    REP(i,n) if(cs[i]!='=')
    {
        if(cs[i]=='R') G[ufind(i)][ufind(i+1)]=true;
        else G[ufind(i+1)][ufind(i)]=true;
    }
    clr(visited);
    REP(i,MAXN) REP(j,MAXN) if(G[i][j]) indegree[j]++;
    REP(i,N)a[i]=1;
    while(true)
    {
        int mini=-1;
        REP(i,N) if(!visited[i]&&indegree[i]==0&&pre[i]==i)
        {
            mini=i;break;
        }
        if(mini==-1) break;
        visited[mini]=true;
        REP(i,N) if(G[mini][i]) indegree[i]--,a[i]=max(a[i],a[mini]+1);
    }
    REP(i,N) a[i]=a[pre[i]];
    REP(i,N) printf("%d ",a[i]);
    printf("\n");
    return 0;
}

