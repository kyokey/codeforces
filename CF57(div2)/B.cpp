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
#define  MAXN     761
#define  eps      1e-6
char cs[MAXN];
char ct[MAXN];
string s[3];
bool isbad(char c)
{
    if(c==';'||c=='-'||c=='_') return true;
    return false;
}
void inits(string &s)
{
    scanf("%s",cs);
    int top=0,len=strlen(cs);
    REP(i,len) if(!isbad(cs[i])) ct[top++]=cs[i];
    ct[top]=0;
    s=string(ct);
}
int geti(char c)
{
    if(c>='a') return c-'a';
    return c-'A';
}
bool isequal(const string &a,const string &b)
{
    if(a.length()!=b.length()) return false;
    REP(i,a.length())
    {
        int t1=geti(a[i]),t2=geti(b[i]);
        if(t1!=t2) return false;
    }
    return true;
}
int main()
{
    REP(i,3) inits(s[i]);
    int n;scanf("%d",&n);
    REP(i,n)
    {
        string t;
        inits(t);
        sort(s,s+3);
        bool f=false;
        do{
            string tmp=s[0]+s[1]+s[2];
            if(isequal(tmp,t))
            {
                f=true;break;
            }
        }while(next_permutation(s,s+3));
        if(f) printf("ACC\n");
        else printf("WA\n");
    }
    return 0;
}
