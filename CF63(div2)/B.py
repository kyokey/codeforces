f=lambda:map(int, raw_input().split())
n,m=f();a=[f() for i in range(m)]
r=0
for i in range(1,n+1):
    t=[(a[j][2],j) for j in xrange(len(a)) if a[j][0]<=i<=a[j][1]]
    r+=a[min(t)[1]][3] if t else 0
print r
