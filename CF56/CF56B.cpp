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
#define  MAXN     13
#define  eps      1e-6
char cs[MAXN][MAXN][MAXN];
bool G[MAXN][MAXN][MAXN];
int K,N,M;
int dk[]={-1,1,0,0,0,0};
int dx[]={0,0,-1,1,0,0};
int dy[]={0,0,0,0,-1,1};
void dfs(int a,int b,int c)
{
    REP(i,6)
    {
        int x=a+dk[i],y=b+dx[i],z=c+dy[i];
        if(x>=0&&x<K&&y>=0&&y<N&&z>=0&&z<M)
        {
            if(cs[x][y][z]!='#'&&!G[x][y][z]) G[x][y][z]=true,dfs(x,y,z);
        }
    }
}
int main()
{
    clr(G);
    scanf("%d%d%d",&K,&N,&M);
    REP(i,K)
    {
        REP(j,N) scanf("%s",cs[i][j]);
    }
    int bgx,bgy;scanf("%d%d",&bgx,&bgy);
    bgx--,bgy--;G[0][bgx][bgy]=true;dfs(0,bgx,bgy);
    int ret=0;
    REP(i,K)REP(j,N)REP(k,M) if(G[i][j][k]) ret++;
    printf("%d\n",ret);
    return 0;
}
