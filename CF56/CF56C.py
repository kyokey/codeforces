import sys
def dogcd(a,b):
    while b!=0:
        a,b=b,a%b
    return a
def dolcm(a,b):
    return a*b/dogcd(a,b)
def dfs(u):
    for i in xrange(len(G[u])):
        v=G[u][i];g=gcd[u][i];l=lcm[u][i]
        tv=l/tval[u]*g
        if not 1<=tv<=MAXV:
            return False        
        if dolcm(tv,tval[u])!=l or dogcd(tv,tval[u])!=g:
            return False
        if tval[v]==0:
            tval[v]=tv
            if not dfs(v):
                return False
        else:
            if tval[v]!=tv:
                return False
    return True
f=lambda:map(int, raw_input().split())
MAXV=1000000
N,M=f()
G=[[] for i in xrange(N)]
gcd=[[] for i in xrange(N)]
lcm=[[] for i in xrange(N)]
val=[0]*N
for i in xrange(M):
    a,b,g,l=f()
    a-=1;b-=1;
    G[a].append(b);G[b].append(a)
    gcd[a].append(g);gcd[b].append(g)
    lcm[a].append(l);lcm[b].append(l)
for i in xrange(N):
    if val[i]==0 :
        ok=False
        if len(G[i])==0:
            val[i]=1
            continue
        minv=reduce(dolcm,gcd[i],1)
        maxv=reduce(dogcd,lcm[i],lcm[i][0])
        for v in xrange(minv,maxv+1,minv):
            tval=val[:]
            tval[i]=v
            if dfs(i):
                ok=True
                val=tval[:]
                break
        if not ok:
            print 'NO'
            sys.exit()
print 'YES'
print ' '.join(map(str,val))
