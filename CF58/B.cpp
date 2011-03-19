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
#define  MAXN     200061
#define  eps      1e-6
typedef long long int64;
char cs[MAXN];
char ct[MAXN];
vector<int> a[26];
int N,K,n,m;
int geti(int v,int idx)
{
    vector<int> &b=a[v];
    if(b.size()==0) return -1;
    int l=0,r=b.size()-1;
    while(l<=r)
    {
        if(l+3>r)
        {
            l-=2;r+=2;l=max(l,0);r=min(r,(int)b.size()-1);
            int ret=inf;
            rep(i,l,r+1) ret=min(ret,abs(b[i]-idx));
            return ret;
        }
        int mid=(l+r)/2;
        if(b[mid]==idx) return 0;
        if(b[mid]<idx) l=mid+1;
        if(b[mid]>idx) r=mid-1;
    }
    return -1;
}
int main()
{
    scanf("%d%d%s",&N,&K,cs);
    REP(i,26)a[i].clear();
    n=strlen(cs);
    REP(i,n) a[cs[i]-'a'].push_back(i);
    REP(i,26) sort(a[i].begin(),a[i].end());
    REP(i,N)
    {
        scanf("%s",ct);
        m=strlen(ct);
        int64 ans=0;
        REP(j,m)
        {
            int t=geti(ct[j]-'a',j);
            if(t<0) ans+=m;
            else ans+=t;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
