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
#define  MAXN     10000
#define  eps      1e-6
bool mem[MAXN];
void dobad()
{
    printf("-1\n");
    exit(0);
}
int main()
{
    clr(mem);
    int n,m;scanf("%d%d",&n,&m);
    char cs[25];
    REP(i,m)
    {
        bool f;int t;scanf("%s",cs);scanf("%s",cs);scanf("%s",cs); f=(cs[0]=='l');
        scanf("%s",cs);scanf("%d",&t);
        if(f)
        {
            if(t<=1) dobad();
            rep(i,t,n+1) mem[i]=true;
        }
        else
        {
            if(t>=n) dobad();
            rep(i,1,t+1) mem[i]=true;
        }
    }
    int cnt=0;rep(i,1,n+1) if(!mem[i]) cnt++;
    if(cnt==0) dobad();
    printf("%d\n",cnt);
    return 0;
}
