import sys
def rec(y,z):
    if y != 0:
        rec(pre[y][z],y)
        print y,
f=lambda :map(int,raw_input().split())
N,M,K=f()
G=[[] for v in xrange(N+1)]
for i in xrange(M):
    u,v=f()
    G[u].append(v)
    G[v].append(u)
exset=set()
for i in xrange(K):
    exset.add(tuple(f()))
pre=[ [0]*(N+1) for i in xrange(N+1)]
dp=[ [1000000]*(N+1) for i in xrange(N+1)]
dp[0][1]=0
qu=[(0,1)]
while qu:
    x,y=qu.pop(0)
    for z in G[y]:
        if (x,y,z) not in exset and dp[x][y]+1 < dp[y][z]:
            pre[y][z]=x
            dp[y][z]=dp[x][y]+1
            qu.append((y,z))
            if(z==N):
                print dp[y][z]
                rec(y,z)
                print N
                sys.exit(0)
print -1
