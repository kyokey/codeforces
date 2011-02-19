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
#define  MAXN     5000061
#define  eps      1e-6
typedef long long int64;
char cs[MAXN];
int dp[MAXN];
int main()
{
    scanf("%s",cs);
    clr(dp);int len=strlen(cs);
    int sh=0,rsh=0,p=1;
    #define MD  131
    REP(i,len)
    {
        sh=sh*MD+cs[i],rsh=cs[i]*p+rsh,p*=MD;
        if(sh==rsh) dp[i+1]=dp[(i+1)/2]+1;
    }
    int64 ret=0;REP(i,len+1) ret+=dp[i];
    printf("%I64d\n",ret);
    return 0;
}
