f=lambda: map(int, raw_input().split())
g=lambda x: ' '.join(map(str, x))
N=f()[0];a=f();b=[f() for i in xrange(N)];K=f()[0]
key, vk=filter(lambda (x,y): K in y, enumerate(b))[0]
vk.remove(K)
if  a.index(K)>min(map(a.index, vk)):
    a.remove(K)
    print g(sorted(a))
else:
    def getset(l):
        r=set()
        map(r.update, l)        
        return r
    l1=getset(b[:key])
    l2=set(filter(lambda x: x<max(vk), l1))
    l3=l1-l2
    l4=getset(b[key+1:])
    print g(sorted(l2|set(vk))+sorted(l3|l4))
