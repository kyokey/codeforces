f=lambda: map(int,raw_input().split())
N,K=f()
a=f()
ret=0
while(True):
    t=[1 if v==K else 0 for v in a];
    if all(t):
        break
    ret+=1
    visited=[0]*101
    for i in xrange(len(a)):
        if a[i]<K and not visited[a[i]]:
            visited[a[i]]=1;a[i]+=1
    sorted(a)
print ret        