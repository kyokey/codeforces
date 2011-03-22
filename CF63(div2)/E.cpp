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
#define  MAXN     100061
#define  eps      1e-6
typedef pair<int,int> pii;
int N,K;
int a[MAXN];
map<int,int> mii;
set<pii> sp;
void print()
{
    pii res=*sp.begin();
    if(res.first==1) printf("%d\n",-res.second);
    else printf("Nothing\n");
}
int main()
{
    scanf("%d%d",&N,&K);
    REP(i,N) scanf("%d",a+i);
    REP(i,N) a[i]=-a[i];
    REP(i,K) mii[a[i]]++;
    FOREACH(it,mii) sp.insert(make_pair(it->second,it->first));
    print();
    rep(i,K,N)
    {
        sp.erase(make_pair(mii[a[i-K]],a[i-K]));
        mii[a[i-K]]--;
        if(mii[a[i-K]]>0)sp.insert(make_pair(mii[a[i-K]],a[i-K]));
        if(mii.count(a[i])) sp.erase(make_pair(mii[a[i]],a[i]));
        mii[a[i]]++;
        sp.insert(make_pair(mii[a[i]],a[i]));
        print();
    }
    return 0;
}

