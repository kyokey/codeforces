f=lambda:map(int,raw_input().split())
n=f()[0];a=[f() for i in range(n)]
r=[reduce(lambda x,y:x+y,v,0) for v in zip(*a)]
print 'NO' if any(r) else 'YES'
