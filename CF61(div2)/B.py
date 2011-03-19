f=lambda:map(int, raw_input().split())
n=f()[0]
lst=f()
ret=0
ll=len(lst)
for i in xrange(0,ll):
    l=i-1;r=i+1;tret=1
    while l>=0 and lst[l]<=lst[l+1]:
        l-=1;tret+=1
    while r<ll and lst[r]<=lst[r-1]:
        r+=1;tret+=1
    if(tret>ret):
        ret=tret
print ret
