m,n=map(int,raw_input().split())
mem=[0]*n;cnt=1
for i in xrange(m):
    op=raw_input().split()
    if op[0]=='alloc':
        t=int(op[1])
        f=False
        for j in xrange(n-t+1):
            if not any(mem[j:j+t]):
                print cnt
                mem[j:j+t],cnt,f = [cnt for k in xrange(t)],cnt+1,True
                break
        if not f:
            print 'NULL'
    elif op[0]=='erase':
        t=int(op[1])
        if t!=0 and t in mem:
            mem=[0 if j==t else j for j in mem]
        else:
            print 'ILLEGAL_ERASE_ARGUMENT'            
    else:
        tmp=[j for j in mem if j!=0]
        mem=tmp+[0]*(n-len(tmp))
    