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
#define  MAXN     200061
#define  eps      1e-6
int a[MAXN],b[MAXN],c[MAXN];
int sa[MAXN],sb[MAXN];
int N;
typedef struct node
{
	int l;
	int r;
	int nd;
	int sn;
}node;
node line[MAXN*4];
vector<node> vn;
bool cmp(const node &a,const node &b)
{
    return a.l<b.l;
}
void T_make(int now,int l,int r)
{
    line[now].l=l,line[now].r=r,line[now].nd=a[l-1]-b[l-1];
    int ta=sa[r]-sa[l-1],tb=sb[r]-sb[l-1];
    line[now].sn=ta-tb;
	if(l==r) return;
	int mid=(l+r)>>1;
	T_make(now*2,l,mid);
	T_make(now*2+1,mid+1,r);
	line[now].nd=min(line[2*now].nd,line[2*now].sn+line[2*now+1].nd);
	line[now].nd=min(line[now].nd,ta-tb);
}
void T_count(int now,int l,int r)
{
	if(line[now].l>r||line[now].r<l) return;
	if (line[now].l>=l&&line[now].r<=r)
	{
	    vn.push_back(line[now]);return ;
    }
    T_count(now*2,l,r);
	T_count(now*2+1,l,r);
}
void solve(set<int> &res,bool tf)
{
    sa[0]=sb[0]=0;rep(i,1,2*N+1) sa[i]=sa[i-1]+a[i-1],sb[i]=sb[i-1]+b[i-1];
    T_make(1,1,2*N);
    REP(i,N)
    {
        vn.clear();
        T_count(1,i+1,i+N);
        sort(vn.begin(),vn.end(),cmp);
        int shu=0;
        bool f=false;
        REP(j,SZ(vn))
        {
            if(shu+vn[j].nd<0)f=true;
            shu+=vn[j].sn;
        }
        if(!f)
        {
            if(!tf)res.insert(i+1);
            else res.insert(N-1-i+1);
        }
    }
}
int main()
{
    scanf("%d",&N);REP(i,N) scanf("%d",a+i);
    REP(i,N) scanf("%d",b+i);
    REP(i,N) a[N+i]=a[i],b[N+i]=b[i];
    set<int> res;
    solve(res,false);
    REP(i,N) c[i]=b[i];REP(i,N) b[i]=c[(i+N-1)%N];
    REP(i,N/2) {
        swap(a[i],a[N-1-i]);
        swap(b[i],b[N-1-i]);
        }
    REP(i,N) a[N+i]=a[i],b[N+i]=b[i];
    solve(res,true);
    printf("%d\n",(int)res.size());
    FOREACH(it,res) printf("%d ",*it);
    puts("");
    return 0;
}

