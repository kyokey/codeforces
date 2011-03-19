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
#define  MAXN     3
#define  eps      1e-6
int a,b,c,d,e,f;
bool check()
{
    return  b*d*f>a*c*e;
}
int main()
{
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(d==0)
    {
        printf("Hermione\n");return 0;
    }
    else
    {
        if(c==0)
        {
            printf("Ron\n");return 0;
        }
        else
        {
            if(b==0)
            {
                printf("Hermione\n");return 0;
            }
            else
            {
                if(a==0)
                {
                    printf("Ron\n");return 0;
                }
                else
                {
                    if(f==0)
                    {
                        printf("Hermione\n");return 0;
                    }
                    else
                    {
                        if(e==0)
                        {
                            printf("Ron\n");return 0;
                        }
                        else
                        {
                            if(check()) printf("Ron\n");
                            else printf("Hermione\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}
