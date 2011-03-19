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
#define  MAXN     1000561
#define  eps      1e-6
typedef pair<int,int> pii;
typedef long long int64;
int64 tree1[MAXN];
int64 tree2[MAXN];
int v[MAXN];
int a[MAXN];
int N;
void addv(int64 tree[],int idx,int64 v)
{
    while(idx<MAXN)
    {
        tree[idx]+=v;
        idx+=(idx&-idx);
    }
}
int64 getsum(int64 tree[],int idx)
{
    int64 ret=0;
    while(idx>0)
    {
        ret+=tree[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int getidx(int x)
{
    int l=0,r=N-1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==x) return mid+1;
        if(a[mid]>x) l=mid+1;
        if(a[mid]<x) r=mid-1;
    }
    return -1;
}
int main()
{
    scanf("%d",&N);
    clr(tree1);clr(tree2);
    REP(i,N) scanf("%d",&v[i]);
    REP(i,N) a[i]=v[i];
    sort(a,a+N,greater<int>());
    int64 ret=0;
    REP(i,N)
    {
        int idx=getidx(v[i]);
        int64 tmp=getsum(tree2,idx);
        addv(tree2,idx,getsum(tree1,idx));
        addv(tree1,idx,1);
        ret+=tmp;
    }
    printf("%I64d\n",ret);
    return 0;
}
