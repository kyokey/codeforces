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
int p[10];
int a,b;
bool isok(int v)
{
    sort(p,p+4);
    int cnt=0;
    do{
        int t=v;
        REP(i,4) t%=p[i];
        if(t==v) cnt++;
    }while(next_permutation(p,p+4));
    return cnt>=7;
}
int main()
{
    REP(i,4) scanf("%d",p+i);
    scanf("%d%d",&a,&b);
    int ret=0;
    rep(i,a,b+1) if(isok(i)) ret++;
    printf("%d\n",ret);
    return 0;
}
