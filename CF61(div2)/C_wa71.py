import sys
def solve(head,ins):
    sa,sb=set(),set()
    n=len(head)
    for v in ins:
        sp=v.split('\\')
        now=sp[0]+'\\'+sp[1]
        for i in xrange(2,len(sp)-1):
            now+='\\'+sp[i]
            if(now[:n]==head):
                sa.add((now))
        now+='\\'+sp[len(sp)-1]
        if(now[:n]==head):
            sb.add((now))
    return (len(sa),len(sb))
ins=[]
for s in sys.stdin:
    ins.append(s[:-1])
r1,r2=0,0
for v in ins:
    sp=v.split('\\')
    head=sp[0]+'\\'+sp[1]
    t1,t2=solve(head,ins)
    r1,r2=max(r1,t1),max(r2,t2)
print r1,r2
