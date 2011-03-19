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
int N,K;
int b[MAXN];
int main()
{
    scanf("%d%d",&N,&K);REP(i,N)scanf("%d",b+i+1);
    vector<int> ans;ans.push_back(N);
    for(int i=N-1;i>=1;i--)
    {
        vector<int> tmp;
        int cnt=0;
        bool f=false;
        REP(j,SZ(ans))
        {
            if(!f&&cnt==b[i]) tmp.push_back(i),f=true;
            tmp.push_back(ans[j]);
            if(ans[j]>=i+K) cnt++;
        }
        if(!f) tmp.push_back(i);
        ans=tmp;
  //      REP(j,SZ(ans)) printf("%d ",ans[j]);
    }
    REP(i,SZ(ans)) printf("%d ",ans[i]);
    puts("");
    return 0;
}

