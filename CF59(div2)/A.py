N=input()
lst=[]
for i in xrange(N):
    a,b=raw_input().split()
    lst.append((b,a))
ret=[]
ret+=[b for (a,b) in lst if a=='rat']
ret+=[b for (a,b) in lst if a=='woman' or a=='child']
ret+=[b for (a,b) in lst if a=='man']
ret+=[b for (a,b) in lst if a=='captain']
for v in ret:
    print v